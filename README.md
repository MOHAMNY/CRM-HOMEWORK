# CRM Sistemi (C ile Dinamik Programlama Yaklaşımı)

## 📌 Proje Açıklaması

Bu proje, müşteri destek süreçlerini ve pazarlama yatırımlarını optimize eden C diliyle geliştirilmiş bir CRM (Müşteri İlişkileri Yönetimi) sistemidir.

Sistem dinamik programlama teknikleri kullanarak iki temel işlemi gerçekleştirir:

### 1. Müşteri Destek Temsilcisi Yönlendirme:

Müşteriler ve temsilciler arasındaki uygunluk matrisine göre en iyi eşleşmeyi hesaplar.

Bitmasking ve dinamik programlama kullanılarak en iyi yönlendirme yapılır.

### 2. Pazarlama Kampanyası Seçimi:

Belirli bir bütçe altında, en yüksek yatırım getirisini (ROI) sağlayan kampanyalar belirlenir.

Sırt çantası (Knapsack) problemi mantığında çalışan bir algoritma kullanılır.
## 📂 Proje Dosyaları
### crm.c
Ana CRM sistemi kodu ( müşteri yönlendirme + pazarlama kampanyası seçimi )
## ⚙ Kurulum ve Çalıştırma
### 1️⃣ Derleme
```
gcc crm.c -o crm_sistemi
```
### 2️⃣ Çalıştırma
```
./crm_sistemi
```
