// script.js

const text = [
  "Informatics Engineering Student",
  "Network Enthusiast",
  "Creative Designer",
  "Japanese Language Learner"
];

let index = 0;
let charIndex = 0;
let currentText = "";
let isDeleting = false;

function typeEffect(){

  const typingText = document.getElementById("typing-text");

  if(index < text.length){

    if(!isDeleting && charIndex <= text[index].length){

      currentText = text[index].substring(0, charIndex);
      charIndex++;

    }

    else if(isDeleting && charIndex >= 0){

      currentText = text[index].substring(0, charIndex);
      charIndex--;

    }

    typingText.innerHTML = currentText;

    if(charIndex == text[index].length){
      isDeleting = true;
    }

    if(isDeleting && charIndex === 0){
      isDeleting = false;
      index++;

      if(index === text.length){
        index = 0;
      }
    }

  }

  setTimeout(typeEffect, 120);

}

typeEffect();    