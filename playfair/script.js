function createMatrix(key){
  key = key.toUpperCase().replace(/J/g,'I').replace(/[^A-Z]/g,'');
  let matrix='', seen={};
  for(let c of key) if(!seen[c]){matrix+=c; seen[c]=1;}
  for(let c='A'.charCodeAt(0); c<='Z'.charCodeAt(0); c++){
    let ch=String.fromCharCode(c);
    if(ch==='J') continue;
    if(!seen[ch]) matrix+=ch;
  }
  let arr=[];
  for(let i=0;i<25;i+=5) arr.push(matrix.slice(i,i+5).split(''));
  return arr;
}

function findPos(matrix, ch){
  if(ch==='J') ch='I';
  for(let i=0;i<5;i++)
    for(let j=0;j<5;j++)
      if(matrix[i][j]===ch) return [i,j];
}

function playfairEncrypt(text, key){
  let m=createMatrix(key);
  text = text.toUpperCase().replace(/J/g,'I').replace(/[^A-Z]/g,'');
  let pairs=[], i=0;
  while(i<text.length){
    let a=text[i], b=text[i+1];
    if(!b || a===b){ b='X'; i++; } else i+=2;
    pairs.push([a,b]);
  }
  let res='';
  for(let [a,b] of pairs){
    let [r1,c1]=findPos(m,a), [r2,c2]=findPos(m,b);
    if(r1===r2) { res+=m[r1][(c1+1)%5]+m[r2][(c2+1)%5]; }
    else if(c1===c2) { res+=m[(r1+1)%5][c1]+m[(r2+1)%5][c2]; }
    else { res+=m[r1][c2]+m[r2][c1]; }
  }
  return res;
}

function playfairDecrypt(text, key){
  let m=createMatrix(key);
  text=text.toUpperCase().replace(/[^A-Z]/g,'');
  let res='';
  for(let i=0;i<text.length;i+=2){
    let a=text[i], b=text[i+1];
    let [r1,c1]=findPos(m,a), [r2,c2]=findPos(m,b);
    if(r1===r2) { res+=m[r1][(c1+4)%5]+m[r2][(c2+4)%5]; }
    else if(c1===c2) { res+=m[(r1+4)%5][c1]+m[(r2+4)%5][c2]; }
    else { res+=m[r1][c2]+m[r2][c1]; }
  }
  return res;
}

document.getElementById('encodeBtn').onclick=()=>{
  const key=document.getElementById('key').value;
  const input=document.getElementById('inputText').value;
  document.getElementById('outputText').value=playfairEncrypt(input,key);
};
document.getElementById('decodeBtn').onclick=()=>{
  const key=document.getElementById('key').value;
  const input=document.getElementById('inputText').value;
  document.getElementById('outputText').value=playfairDecrypt(input,key);
};
