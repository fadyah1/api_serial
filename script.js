function voice_recognition(){

var SpeechRecognition = window.SpeechRecognition || webkitSpeechRecognition;
var recognition = new SpeechRecognition();

recognition.lang = 'ar-AE';
recognition.start();

    recognition.onstart= function () {
    document.getElementById("state").innerHTML="Recording is on";
    }

    recognition.onspeechend= function () {
        document.getElementById("state").innerHTML= "Recording is off";
        recognition.stop();
    }

    recognition.onresult= function (event) {
        var transcript = event.results[0][0].transcript;
        tArea.innerHTML=transcript   
    };
}

