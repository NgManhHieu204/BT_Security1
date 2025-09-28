# BT Môn: An toàn và bảo mật thông tin
## Bài tập 1: Nguyễn Mạnh Hiếu - K225480106020
### TÌM HIỂU CÁC PHƯƠNG PHÁP MÃ HOÁ CỔ ĐIỂN
1. Caesar
2. Affine
3. Hoán vị
4. Vigenère
5. Playfair

### Với mỗi phương pháp, hãy tìm hiểu:
1. Tên gọi
2. Thuật toán mã hoá, thuật toán giải mã
3. Không gian khóa
4. Cách phá mã (mà không cần khoá)
5. Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript
_____

1. Caesar

   Tên gọi: Caesar cipher (Cipher dịch) — đặt theo Julius Caesar
   
   Thuật toán mã hoá: C = (P + k) mod 26
   
   Thuật toán giải mã: P = (C − k) mod 26

   Không gian khóa: 26 khả năng (0 - 25)

   Cách phá mã (mà không cần khoá): Không gian khóa có 26 khả năng => thử 26 khả năng
   
   Mã hóa và giải mã:
   
   - HTML,CSS,JS
   
     - Mã hóa
   
     <img width="583" height="714" alt="image" src="https://github.com/user-attachments/assets/96fb45b6-d35c-46f5-a136-bac25465269c" />

     - Giải mã

     <img width="639" height="720" alt="image" src="https://github.com/user-attachments/assets/ce894405-84b5-4c70-aa5b-19a0db61d417" />

   - C++


2. Affine

   Tên gọi: Affine cipher — biến đổi affine trong modulo 26
   
   Thuật toán mã hoá: C = (a*P + b) mod 26
   
   Thuật toán giải mã: P = a^-1(C − b) mod 26 với a^-1 là nghịch đảo modulo 26 (chỉ tồn tại khi gcd(a,26)=1).

   Không gian khóa:
   
   - a có các giá trị coprime với 26 là: (1,3,5,7,9,11,15,17,19,21,23,25) (12 giá trị)
   
   - b có 26 giá trị (0-25) ===> tổng không gian khóa 12*36 = 312

   Cách phá mã (mà không cần khoá):
   
   - Thử mọi cặp (a,b) (312 phép)

   - Phân tích tần suất cũng hữu dụng
   
   Mã hóa và giải mã:
   
    - HTML,CSS,JS
   
      - Mã hóa:

       <img width="607" height="801" alt="Screenshot 2025-09-27 163340" src="https://github.com/user-attachments/assets/c1e97e05-5280-4c97-a91d-99c2003adb7a" />
   
      - Giải mã:

       <img width="658" height="792" alt="image" src="https://github.com/user-attachments/assets/e7583e7c-d38d-4210-8420-3b30c1958966" />

    - C++
   
3. Hoán vị

   Tên gọi: Columnar transposition (Hoán vị cột) — loại transposition cipher
   
   Thuật toán mã hoá:

     - Lấy khóa độ dài k (ví dụ chuỗi số chỉ thứ tự cột hoặc từ khóa chữ cái -> chuyển thành thứ tự)
    
     - Viết bản rõ vào ma trận theo hàng, mỗi hàng k ký tự (nếu thiếu thì thêm ký tự đệm như 'X')
    
     - Đọc các cột theo thứ tự khóa và ghép lại
   
   Thuật toán giải mã: Biết chiều cột k và thứ tự khóa, tính số hàng rồi điền theo thứ tự cột, sau đó đọc theo hàng

   Không gian khóa: Nếu khóa là một hoán vị của k cột thì số hoán vị = k!. Nếu sử dụng chuỗi chữ (để sinh thứ tự), độ lớn phụ thuộc k

   Cách phá mã (mà không cần khoá):
   
   - Phân tích cấu trúc: dò chiều dài cột/hàng, hoặc dùng biết trước các mẫu từ ngữ, dùng tấn công brute-force trên các hoán vị nếu k nhỏ

   - Kết hợp với phân tích ngữ nghĩa: so sánh với từ điển
   
   Mã hóa và giải mã:
   
    - HTML,CSS,JS
   
      - Mã hóa:

       <img width="669" height="712" alt="Screenshot 2025-09-28 132306" src="https://github.com/user-attachments/assets/bc476197-7f4c-42b6-894c-93dee32090c0" />
   
      - Giải mã:

       <img width="631" height="681" alt="Screenshot 2025-09-28 132329" src="https://github.com/user-attachments/assets/9503d0c1-793d-4374-b105-3ee0bb1c5906" />

    - C++

4. Vigenère

   Tên gọi: Vigenère cipher — polyalphabetic substitution
   
   Thuật toán mã hoá: với khóa chuỗi 𝐾 K, ký tự 𝑃 𝑖 P i ​ và ký tự khóa 𝐾 𝑗 K j ​ đưa về 0..25:

     - Ci​ = (Pi​ + Kj​) mod 26 với Kj​ lặp lại nếu ngắn hơn bản rõ
   
   Thuật toán giải mã: Pi ​= (Ci​ − Kj​) mod 26

   Không gian khóa: Nếu khóa độ dài L và mỗi ký tự 26 khả năng, keyspace = 26 𝐿 26 L . Thực tế tìm khóa bằng Kasiski/Friedman nếu L nhỏ

   Cách phá mã (mà không cần khoá):
   
   - Kasiski examination để tìm độ dài khóa

   - Sau khi biết độ dài, tách thành L chuỗi và dùng phân tích tần suất cho từng chuỗi

   - Friedman test ước lượng độ dài khóa
   
   Mã hóa và giải mã:
   
    - HTML,CSS,JS
   
      - Mã hóa:

        <img width="686" height="777" alt="Screenshot 2025-09-28 133815" src="https://github.com/user-attachments/assets/9502aefa-1fb4-4e9c-8bc7-d7a7515a231f" />

      - Giải mã:

       <img width="689" height="777" alt="Screenshot 2025-09-28 133848" src="https://github.com/user-attachments/assets/2430ecdc-a0be-48d4-b1a6-28d861670e23" />

    - C++

5. Playfair

   Tên gọi: Playfair cipher — substitution bằng cặp (digram) dùng ma trận 5×5
   
   Thuật toán mã hoá:

     - Tạo ma trận 5×5 từ khóa (loại bỏ ký tự trùng, gộp I/J)
     
     - Chuẩn bị bản rõ: loại bỏ ký tự không chữ, thay J→I, chia thành cặp, nếu hai ký tự giống nhau chèn 'X' vào giữa, nếu lẻ thêm 'X'
     
     - Mã hóa mỗi cặp:

       - Nếu cùng hàng: thay mỗi chữ bằng chữ bên phải (vòng trở lại)

       - Nếu cùng cột: thay bằng chữ bên dưới

       - Nếu khác hàng và khác cột: thay bằng các chữ ở cùng hàng nhưng hoán cột (rectangle)
   
   Thuật toán giải mã: ngược lại (trái / trên / rectangle)

   Không gian khóa: Khóa là chuỗi ký tự, ma trận 5×5 có 25! / ? — nhưng thực tế không gian khóa hữu hạn lớn; tuy nhiên Playfair không an toàn trước máy tính hiện đại

   Cách phá mã (mà không cần khoá): Phân tích bigram, tấn công bằng tần suất theo cặp, hoặc brute-force trên không gian khóa nhỏ (khó). Tấn công hiện đại sử dụng mô hình đánh giá điểm (hill climbing).

   Mã hóa và giải mã:
   
    - HTML,CSS,JS
   
      - Mã hóa:
  
       <img width="618" height="783" alt="Screenshot 2025-09-28 134156" src="https://github.com/user-attachments/assets/73116a5a-bba5-4b8b-bed8-31b447fb8923" />

      - Giải mã:

       <img width="618" height="787" alt="Screenshot 2025-09-28 134238" src="https://github.com/user-attachments/assets/01b95a2c-f52d-443c-a7ee-9fc31789b537" />

    - C++
   
