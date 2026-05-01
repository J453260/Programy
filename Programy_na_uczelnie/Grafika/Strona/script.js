let hoverCount = 0;
let clickCount = 0;

const button = document.getElementById("myButton");
const hoverDisplay = document.getElementById("hoverCount");
const clickDisplay = document.getElementById("clickCount");

button.addEventListener("mouseenter", () => {
    hoverCount++;
    hoverDisplay.textContent = hoverCount;
});

button.addEventListener("click", () => {
    clickCount++;
    clickDisplay.textContent = clickCount;
});

const canvas = document.getElementById("myCanvas");
const ctx = canvas.getContext("2d");

ctx.fillStyle = "blue";
ctx.fillRect(20, 20, 100, 60);

ctx.beginPath();
ctx.arc(200, 100, 40, 0, Math.PI * 2);
ctx.fillStyle = "red";
ctx.fill();
ctx.closePath();
