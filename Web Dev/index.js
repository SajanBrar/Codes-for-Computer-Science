let display = document.getElementById('display');
let buttons = Array.from(document.getElementsByClassName('button'));

buttons[9].addEventListener('click',but=>{
    let str = display.innerText;
    let strr = String(Math.sin(Number(str)));
    display.innerText = strr.slice(0,-3);
})
buttons.map(button => {
    button.addEventListener('click', (e) => {
        switch (e.target.innerText) {
            case 'C':
                display.innerText = '';
                break;
            case '=':
                try {
                    display.innerText = eval(display.innerText);
                } catch {
                    display.innerText = "Error"
                }
                break;
            case '←':
                if (display.innerText) {
                    display.innerText = display.innerText.slice(0, -1);
                }
                break;
            default:
                display.innerText += e.target.innerText;
        }
    });
});