function vigenere(text, key, decode=false){
  key = key.toUpperCase().replace(/[^A-Z]/g,'');
  let res='', j=0;
  for(let i=0;i<text.length;i++){
    let c=text[i];
    if(/[A-Za-z]/.test(c)){
      const base = c<='Z'?65:97;
      const k = key[j % key.length].charCodeAt(0) - 65;
      const shift = decode ? (26 - k) : k;
      res += String.fromCharCode((c.toUpperCase().charCodeAt(0)-65+shift)%26 + base);
      j++;
    } else res += c;
  }
  return res;
}

document.getElementById('encodeBtn').onclick=()=>{
  const key=document.getElementById('key').value;
  const input=document.getElementById('inputText').value;
  document.getElementById('outputText').value=vigenere(input,key,false);
};
document.getElementById('decodeBtn').onclick=()=>{
  const key=document.getElementById('key').value;
  const input=document.getElementById('inputText').value;
  document.getElementById('outputText').value=vigenere(input,key,true);
};
