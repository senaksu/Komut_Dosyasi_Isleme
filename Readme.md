# Komut Dosyası İşleme Uygulaması

**Sena Aksu** - **b211210008**  

## Proje Amacı

Bu proje, C programlama dilinde `libfdr` kütüphanesini kullanarak bir metin işleme uygulaması geliştirmeyi amaçlamaktadır. Uygulama, belirli komutlarla metin dosyalarını okuyup işleyerek çeşitli işlemler gerçekleştirecek ve sonuçları çıktı dosyasına yazacaktır.

## İçerik

- **main.c**: Ana program dosyası. Komutları işleyen ana fonksiyonlar burada bulunur.
- **jval.h**: Jval yapısı ve ilgili fonksiyonlar burada tanımlanır.
- **jrb.h**: Red-Black Tree (Kırmızı-Siyah Ağaç) yapısı ve ilgili fonksiyonlar burada tanımlanır.
- **dllist.h**: Doubly Linked List (Çift Bağlı Liste) yapısı ve ilgili fonksiyonlar burada tanımlanır.
- **fields.h**: Alan işlemleri için gerekli yapılar ve ilgili fonksiyonlar burada tanımlanır.
- **makefile**: Projenin derlenmesi ve çalıştırılması için Makefile dosyası.
- **giris.dat**: Örnek giriş verileri dosyası.

## Derleme ve Çalıştırma

Projeyi derlemek ve çalıştırmak için şu adımları izleyebilirsiniz:

1. Terminal veya komut istemcisini açın.
2. Proje dizinine gidin: `cd /path/to/proje_dizini`
3. Makefile'ı kullanarak projeyi derleyin: `mingw32-make`
4. Oluşturulan yürütülebilir dosyayı çalıştırın: `bin/sistem giris.dat cikis.dat`

