let isConnected = false;
let port ;
let enc= new TextEncoder();
let writer;

async function onVoice(){
if(isConnected==false){
    console.log("not working plz make sure you have connected the device");
}
try {
    const computerText = `${command}@`;
    await writer.write(enc.encode(computerText));
  } catch (e) {
    console.log('error check the onVoice function', e);
  }
}

async function onConnectedUsb(){
    try{
        const requestOptions ={
            filters: [{usbVendorId: 0x2341}],
        };

        port = await navigator.serial.requestPort(requestOptions);
        await port.open({buadrate: 115200});
        writer = port.writable.getWriter();
        isConnected = true;
    }catch (e){
        console.log('error', e);
    }

}