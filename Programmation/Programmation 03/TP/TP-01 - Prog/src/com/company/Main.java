import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) throws IOException {

        // Verifie si fichier est valide
        try {
            String fileLocation = "";
            int offset = 0;
            int length = 0;
            boolean isLengthSpec = false;
            boolean isOS = false;
            boolean isString = false;

            // Gestion des arguments
            for (int i = 0; i < args.length; i++) {
                String arg = args[i];
                switch (arg) {
                    case "-o":
                        offset = Integer.parseInt(args[i + 1]);
                        break;
                    case "-l":
                        length = Integer.parseInt(args[i + 1]);
                        isLengthSpec = true;
                        break;
                    case "-f":
                        fileLocation = args[i + 1];
                        break;
                    case "-i":
                        isOS = true;
                        break;
                    case "-s":
                        isString = true;
                        break;
                    default:
                        break;
                }
            }
            RandomAccessFile file = new RandomAccessFile(fileLocation, "r");

            if (isOS) {
                printFormat(file);
            } else if (isString) {
                printStrings(file, offset, length, (byte) 4);
            } else {
                if (!isLengthSpec) {
                    length = (int) file.length();
                }
                /**
                 * Verification si..
                 * offset (-o) est >= 0 et < que la taille du fichier.
                 * length (-l) est > 0 et <= que la taille du fichier - le décalage.
                 */
                if (offset >= 0 || offset < file.length() || length > 0 || length <= file.length()) {
                    printData(file, offset, length);
                } else {
                    printUsage();
                }
            }
        } catch (Exception e) {
            printUsage();
            System.out.println(e.getMessage());
        }

    }

    public static void printData(RandomAccessFile file, long offset, long length) throws IOException {
        printHead();
        printMemHex(file, offset, length);

        file.close();
    }

    /**
     * Print si il y a un probleme
     */
    public static void printUsage() {
        System.out.println("" +
                "-o : Offset \n" +
                "-l : Le décalage \n" +
                "-f (obligatoire): Fichier choisit \n" +
                "-i : Format OS \n" +
                "-s : Chaine de characters");
    }

    /*
     * Print 1..F - Yellow
     * Print ASCII - White
     */
    public static void printHead() {
        System.out.print("\t" + "\t" + "\s" + "\s");
        for (int index = 0; index < 16; index++) {
            System.out.printf("\u001b[33m\s%X\s", index); // Les index 1..F
        }
        System.out.print("\sASCII");
    }

    /**
     * Fonction pour print le tableau de Memory Adress, Char in HEX et ASCII
     *
     * @param file le fichier
     * @throws IOException
     */
    public static void printMemHex(RandomAccessFile file, long offset, long length) throws IOException {
        int start = (int) offset;
        int max = (int) offset;
        /**
         * Print Memory - Yellow
         * Print Short in Hex - Blue
         */
        file.seek(offset);
        for (long i = offset; i < length + 1; i++) {
            if (i % 17 == 0) {
                System.out.print(" ");
                for (int j = start; j < max; j++) {
                    file.seek(j);
                    if (!String.valueOf((char) file.read()).matches(".")) {
                        System.out.print(".");
                    } else {
                        file.seek(j);
                        System.out.print("\u001b[37m" + (char) file.read()); // ASCII Char
                    }
                    start++;
                }

                System.out.print("\n\u001b[33m0x00000" + i / 17 + "0\s"); // Memory adress
                max += 16;
            } else {
                System.out.printf("\u001b[36m%02X\s", file.read()); // Char in Hex
            }
            file.seek(i);
        }
        printLastLine(file, start, max);

        file.close();
    }

    public static void printLastLine(RandomAccessFile file, int start, int max) throws IOException {
        for (int i = start; i < max; i++) {
            System.out.print(" ");
            for (int j = start; j < max; j++) {
                file.seek(j);
                if (!String.valueOf((char) file.read()).matches(".")) {
                    System.out.print(".");
                } else {
                    file.seek(j);
                    System.out.print("\u001b[37m" + (char) file.read()); // ASCII Char
                }
                start++;
            }
        }
    }

    public static void printStrings(RandomAccessFile file, long offset, long length, byte minLenght) throws IOException {
        int zeroCounter = 0;
        byte[] tabByte = new byte[(int) length];

        file.read(tabByte);
        for (int i = (int) offset; i < length; i++) {
            if (tabByte[i] > 0) {
                zeroCounter = zeroCounter + 1;
            } else if (zeroCounter >= minLenght) {
                do {
                    file.seek(i - zeroCounter);
                    System.out.print((char) file.read());
                    zeroCounter = zeroCounter - 1;
                } while (!(zeroCounter == 0));
            } else {
                zeroCounter = 0;
            }
        }
    }

    public static void printFormat(RandomAccessFile file) throws IOException {
        String platformString = "";
        ArrayList<String> platformArray = new ArrayList<String>();

        // Ajoute tout les byte dans un arraylist de string.
        for (int i = 0; i < file.length(); i++) {
            platformArray.add(String.valueOf(file.read()));
        }

        // Ajoute les quatres premier byte dans un string. Permet de savoir quel os.
        file.seek(0);
        for (int i = 0; i < 4; i++) {
            platformString = platformString.concat(String.valueOf(file.read()));
        }

        System.out.println();

        // Codes OS
        // 77901440 = Microsoft
        // 127697670 = Linux
        // 207250237254 = MacOS
        switch (platformString) {
            case "77901440":
                if ((platformArray.get(256).equals("80")) && (platformArray.get(257).equals("69"))) {
                    file.seek(24);
                    System.out.println("OS: PE");
                    System.out.println("Machine: x" + file.read());
                } else {
                    System.out.println("OS: MZ");
                    System.out.println("Machine: x86");
                }
                break;
            case "127697670":
                file.seek(4);
                System.out.println("OS: Linux");
                System.out.println("Machine: " + findMachine(platformArray, file.read()));
                break;
            case "207250237254":
                file.seek(0);
                System.out.println("OS: MacOS");
                System.out.println("Machine: " + findMachine(platformArray, file.read()));
                break;
            default:
                printUsage();
                break;
        }
    }

    public static String findMachine(ArrayList<String> platformArray, int lookingByte) {
        String machineType = "";

        switch (lookingByte) {
            case 1:
                machineType = "x32";
                break;
            case 2:
                machineType = "x64";
                break;
            case 206: // 206 car CE
                machineType = "x32";
                break;
            case 207: // 207 car CF
                machineType = "x64";
                break;
            default:
                System.out.println("Une erreur est survenue");
                System.out.println(lookingByte);
                break;
        }

        return machineType;
    }
}