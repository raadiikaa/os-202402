# 📝 Laporan Tugas Akhir

**Mata Kuliah**: Sistem Operasi
**Semester**: Genap / Tahun Ajaran 2024–2025
**Nama**: Radika Rismawati Tri Prasaja
**NIM**: 240202905
**Modul yang Dikerjakan**:
# 🧪 Modul 5 – Audit dan Keamanan Sistem (xv6-public)

## 📌 Deskripsi Singkat Tugas

**Modul 5 – Audit dan Keamanan Sistem**:  
Menambahkan fitur audit system call di kernel XV6. Setiap pemanggilan system call dicatat ke dalam *audit log*. Log ini hanya bisa diakses oleh proses dengan PID 1 melalui system call `get_audit_log()`.

---

## 🛠️ Rincian Implementasi

* Menambahkan struktur `audit_entry` dan array `audit_log` di `syscall.c`
* Menambahkan pencatatan system call dalam fungsi `syscall()` di `syscall.c`
* Menambahkan system call `get_audit_log()` di `sysproc.c`
* Mengedit `syscall.c` untuk mendaftarkan syscall baru
* Mengedit `user.h`, `usys.S`, dan `syscall.h` untuk mendeklarasikan syscall
* Menambahkan program uji `audit.c`
* Mengedit `Makefile` untuk menyertakan program `audit`

---

## ✅ Uji Fungsionalitas

Program uji yang digunakan:

* `audit`: untuk menampilkan isi audit log system call

Pengujian dilakukan dengan menjalankan `audit` sebagai proses dengan PID 1, yakni dengan mengganti `init` shell default menjadi `audit` di `init.c`.

---

## 📷 Hasil Uji

### 📍 Output `audit`:

```
=== Audit Log ===
[0] PID=1 SYSCALL=7 TICK=1
[1] PID=1 SYSCALL=15 TICK=2
[2] PID=1 SYSCALL=16 TICK=2
[3] PID=1 SYSCALL=15 TICK=3
[4] PID=1 SYSCALL=10 TICK=3
[5] PID=1 SYSCALL=16 TICK=3
[6] PID=1 SYSCALL=16 TICK=3
[7] PID=1 SYSCALL=16 TICK=3
[8] PID=1 SYSCALL=16 TICK=3
...
```

📸 **Screenshot** hasil uji (PID 1 menjalankan `audit`):

![hasil audit](./Screenshoot/HasilModul5.png)

---

## ⚠️ Kendala yang Dihadapi

* Jika `audit` dijalankan sebagai user biasa (bukan PID 1), system call `get_audit_log()` mengembalikan error (`-1`)
* Harus mengubah `init.c` agar proses `audit` dijalankan sebagai proses pertama (PID 1) untuk bisa mengakses log
* Potensi race condition jika sistem memiliki lebih dari satu CPU (tidak di-handle dalam implementasi sederhana ini)

---

## 📚 Referensi

* Buku xv6 MIT: [https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf](https://pdos.csail.mit.edu/6.828/2018/xv6/book-rev11.pdf)
* Repositori xv6-public: [https://github.com/mit-pdos/xv6-public](https://github.com/mit-pdos/xv6-public)
* Panduan praktikum Modul 5
* Diskusi rekan dan dokumentasi kode xv6

---
