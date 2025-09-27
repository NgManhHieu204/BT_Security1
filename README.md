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

