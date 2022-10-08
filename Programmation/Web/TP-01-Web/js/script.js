const currentDate = new Date();
const dateTime =
  "Date / Heure: " +
  currentDate.getDay() +
  "/" +
  currentDate.getMonth() +
  "/" +
  currentDate.getFullYear() +
  " @ " +
  currentDate.getHours() +
  ":" +
  currentDate.getMinutes() +
  ":" +
  currentDate.getSeconds();

document.getElementById("date").innerHTML = dateTime;

// Cette fonction permet de changer la langue pour le francais
function changeFrench() {
  // menu
  document.getElementById("support-menu").innerHTML = "support.";
  document.getElementById("monde-menu").innerHTML = "monde.";
  document.getElementById("economie-menu").innerHTML = "économie.";
  document.getElementById("russie-menu").innerHTML = "russie.";
  document.getElementById("ukraine-menu").innerHTML = "ukraine.";

  //hero
  document.getElementById("hero-title").innerHTML =
    "L'Ukraine au <span class='red'>front</span>.";
  document.getElementById("hero-p").innerHTML =
    "<span class='blue'>L'horreur présentée en chiffres et en images.</span>";
  document.getElementById("btn-origin").innerHTML = "origine.";

  //ukraine
  document.getElementById("ukraine-title-num").innerHTML =
    "ukraine en <span class='bleu'>chiffres</span>.";
  document.getElementById("deaths").innerHTML =
    "15 000 <span class='red'>morts</span>.";
  document.getElementById("blesse").innerHTML = "1900 blessées";
  document.getElementById("moved").innerHTML = "2.8 millions déplacées";
  document.getElementById("ukraine-title-images").innerHTML =
    "ukraine en <span class='bleu'>images</span>.";
  document.getElementById("batiment").innerHTML = "1700 bâtiments détruits";
  document.getElementById("dommage").innerHTML =
    "119 milliards en <span class='red'>dommages</span>.";

  // russie
  document.getElementById("russie-title").innerHTML =
    "Réaction du peuple russe.";
  document.getElementById("rev").innerHTML = "révoltes.";
  document.getElementById("des").innerHTML = "désaccord.";
  document.getElementById("manif").innerHTML = "manifestations.";

  // economie
  document.getElementById("econo-title").innerHTML =
    "Chute du <span class='red'>Rouble</span>.";
  document.getElementById("econo-p1").innerHTML =
    "Les États-Unis et l'Union européenne ont déclaré qu'ils excluraient certaines banques russes du système international de paiements bancaires Swift et ont personnellement visé le président russe Vladimir Poutine et son ministre des Affaires étrangères Sergei Lavrov.";
  document.getElementById("econo-p2").innerHTML =
    "Pendant un moment, il fallait plus de <span class='italic'>130 roubles</span> pour faire un dollar américain, et ce jusqu'au 1er janvier.";

  // monde
  document.getElementById("monde-maintitle").innerHTML =
    "<span class='underline-red'>Hausse</span> des prix.";
  document.getElementById("monde-title-01").innerHTML =
    "<span class='red'>Monter</span> de l'essence.";
  document.getElementById("monde-p1").innerHTML =
    "La Russie détient 7% des parts du marché pétrolier. Naturellement, le prix de l'or noir a augmenté puisque l'offre ne soutenait plus la demande.";
  document.getElementById("monde-title-02").innerHTML =
    "<span class='red'>Chute</span> de la bourse.";
  document.getElementById("monde-p2").innerHTML =
    "La peur des investiseurs a créé une certaine volatilité dans les marchés boursiers. Cela fera baisser considérablement tout les secteurs.";
  document.getElementById("monde-title-03").innerHTML =
    "Panier d'épicerie plus <span class='red'>cher</span>.";
  document.getElementById("monde-p3").innerHTML =
    "Le prix des articles que nous mangeons dépend énormément du transport de ce dernier. Si le prix du baril est élevé, les pommes et bananes le seront aussi!";

  // support
  document.getElementById("support-title").innerHTML = "Supporter";
  document.getElementById("support-title-02").innerHTML =
    "L'<span class='red'>Ukraine</span>.";
  document.getElementById("support-p").innerHTML =
    "Payment par BTC, ETC et USDT";

  localStorage.setItem("langue", "francais");
  scrollTop();
}

// Cette fonction permet de changer la langue pour l'anglais
function changeEnglish() {
  // menu
  document.getElementById("support-menu").innerHTML = "support.";
  document.getElementById("monde-menu").innerHTML = "world.";
  document.getElementById("economie-menu").innerHTML = "economy.";
  document.getElementById("russie-menu").innerHTML = "russia.";
  document.getElementById("ukraine-menu").innerHTML = "ukraine.";

  // hero
  let front = String("frontline");
  document.getElementById("hero-title").innerHTML =
    "Ukraine at the <span class='red'>frontline</span>.";
  document.getElementById("hero-p").innerHTML =
    "<span class='blue'>Horror presented in numbers and pictures.</span>";
  document.getElementById("btn-origin").innerHTML = "origin.";

  // ukraine
  document.getElementById("ukraine-title-num").innerHTML =
    "ukraine in <span class='bleu'>numbers</span>.";
  document.getElementById("deaths").innerHTML =
    "15 000 <span class='red'>deaths</span>.";
  document.getElementById("blesse").innerHTML = "1900 hurted";
  document.getElementById("moved").innerHTML = "2.8 millions moved";
  document.getElementById("ukraine-title-images").innerHTML =
    "ukraine in <span class='bleu'>pictures</span>.";
  document.getElementById("batiment").innerHTML = "1700 buildings destroyed";
  document.getElementById("dommage").innerHTML =
    "119 billions in <span class='red'>damages</span>";

  // russie
  document.getElementById("russie-title").innerHTML =
    "Reaction of russia's people.";
  document.getElementById("rev").innerHTML = "revolutions.";
  document.getElementById("des").innerHTML = "revolts.";
  document.getElementById("manif").innerHTML = "manifestations.";

  // economie
  document.getElementById("econo-title").innerHTML =
    "Fall of the <span class='red'>Ruble</span>.";
  document.getElementById("econo-p1").innerHTML =
    "The United States and the European Union have said they will exclude certain Russian banks from the Swift, the international banking payment system, and have personally targeted Russian President Vladimir Putin and his Foreign Minister Sergei Lavrov.";
  document.getElementById("econo-p2").innerHTML =
    "At some time, we needed more than <span class='italic'>130 roubles</span> to make a single USD. This went on until the first of january.";

  // monde
  document.getElementById("monde-maintitle").innerHTML =
    "<span class='underline-red'>Jump</span> of prices.";
  document.getElementById("monde-title-01").innerHTML =
    "<span class='red'>Rise</span> of gasoline.";
  document.getElementById("monde-p1").innerHTML =
    "Russia holds 7% of the oil market share. Naturally, the price of black gold increased since supply no longer supported demand.";
  document.getElementById("monde-title-02").innerHTML =
    "<span class='red'>Fall</span> of the stock market.";
  document.getElementById("monde-p2").innerHTML =
    "Fear from investors created volatility in the stock market. This lowered all sectors considerably.";
  document.getElementById("monde-title-03").innerHTML =
    "Panier d'épicerie plus <span class='red'>cher</span>.";
  document.getElementById("monde-p3").innerHTML =
    "The price of items in your shopping cart greatly depends on transportation. Since transportation requires fuel, then if the price per barrel is high, apples and bananas will be too!";

  // support
  document.getElementById("support-title").innerHTML = "Support";
  document.getElementById("support-title-02").innerHTML =
    "<span class='red'>Ukraine</span>.";
  document.getElementById("support-p").innerHTML =
    "Payment by BTC, ETC and USDT";

  localStorage.setItem("langue", "english");
  scrollTop();
}

// Cette fonction permet d'enregistrer la langue dans le navigateur
function storeLan() {
  const langueChoisit = localStorage.getItem("langue");

  if (langueChoisit === "francais") {
    changeFrench();
  } else if (langueChoisit === "english") {
    changeEnglish();
  }
}

// Cette fonction permet de "scroller" jusqu'en haut du navigateur
function scrollTop() {
  window.scrollTo({ top: 110, behavior: "smooth" });
}

// Cette fonction permet de "scroller" jusqu'a un div
function scrollAction(anchorScroll) {
  document
    .getElementById(anchorScroll)
    .scrollIntoView({ behavior: "smooth", block: "start" });
}

// Cette fonction permet de faire apparaitre de facon graduel un div
function reveal() {
  var reveals = document.querySelectorAll(".economie");

  for (var i = 0; i < reveals.length; i++) {
    var windowHeight = window.innerHeight;
    var elementTop = reveals[i].getBoundingClientRect().top;
    var elementVisible = 150;

    if (elementTop < windowHeight - elementVisible) {
      reveals[i].classList.add("active");
    } else {
      reveals[i].classList.remove("active");
    }
  }
}

window.addEventListener("scroll", reveal);
window.onload = storeLan();
