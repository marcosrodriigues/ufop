var inputTamanho = document.querySelector('[name=tamanho]');
var outputTamanho = document.querySelector('[name=valortamanho]');

inputTamanho.oninput = function() {
    outputTamanho.value = inputTamanho.value
}