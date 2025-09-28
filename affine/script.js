// Tính gcd để kiểm tra tính hợp lệ của a
function gcd(x, y) {
  return y === 0 ? x : gcd(y, x % y);
}

// Tìm nghịch đảo modulo 26
function modInverse(a, m) {
  a = ((a % m) + m) % m;
  for (let x = 1; x < m; x++) {
    if ((a * x) % m === 1) return x;
  }
  return null; // không có nghịch đảo
}

function affineCipher(text, a, b, decode = false) {
  const m = 26;
  text = text.toLowerCase();
  return text.replace(/[a-z]/g, ch => {
    const x = ch.charCodeAt(0) - 97;
    let y;
    if (!decode) {
      y = (a * x + b) % m;
    } else {
      const aInv = modInverse(a, m);
      if (aInv === null) return ch;
      y = (aInv * (x - b + m)) % m;
    }
    return String.fromCharCode(y + 97);
  });
}

// Sự kiện nút
document.getElementById('encodeBtn').onclick = () => {
  const a = parseInt(document.getElementById('a').value);
  const b = parseInt(document.getElementById('b').value);
  const text = document.getElementById('inputText').value;

  if (!a || gcd(a,26) !== 1) {
    alert("Giá trị a phải nguyên dương và gcd(a,26)=1");
    return;
  }
  document.getElementById('outputText').value = affineCipher(text, a, b);
};

document.getElementById('decodeBtn').onclick = () => {
  const a = parseInt(document.getElementById('a').value);
  const b = parseInt(document.getElementById('b').value);
  const text = document.getElementById('inputText').value;

  if (!a || gcd(a,26) !== 1) {
    alert("Giá trị a phải nguyên dương và gcd(a,26)=1");
    return;
  }
  document.getElementById('outputText').value = affineCipher(text, a, b, true);
};
