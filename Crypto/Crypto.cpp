// Crypto.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <openssl/conf.h> //функции, структуры и константы настройки OpenSSL
#include <openssl/evp.h> //сами криптографические функции https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h>// коды внутренних ошибок OpenSSL и их расшифровка
#include <fstream>
#include <bitset>
#include <openssl\aes.h>
using namespace std;

int main()
{
	// Как правило, в литературе, структуры используются для хранения только данных
	// и ни слова о методах, конструкторах и деструкторах
	struct name_of_my_struct //сродни классу
	{
		name_of_my_struct() 
		{

		}
		int a;
		double b;
		int fnc1() {
			return a;
		}
};
	unsigned char *vhod = (unsigned char *)"Some folks are born to wave away the flag"; 
	int vhod_dl = strlen((char *)vhod);
	unsigned char *kluch = (unsigned char*)"0123456789";
	unsigned char *iv = (unsigned char*)"0123456789012345";
	unsigned char cryptedtext[256];
	unsigned char decryptedtext[256];

	// 1.Создается указатель на несуществующую структуру
	EVP_CIPHER_CTX *ctx;

	//2. Для указателя создается пустая структура настроек  (метод, ключ, вектор инициализации и тд)
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода

	//3.Структура EVP_CIPHER_CTX заполняется настройками
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, kluch, iv); //инициализация методом AES, ключом и вектором

	//4. Сам процесс шифрования - функция EVP_EncryptUpdate
	int len;
	EVP_EncryptUpdate(ctx, cryptedtext, &len, vhod, vhod_dl); //ШИФРОВАНИЕ
	int cryptedtext_len = len;

	//5. Финализация процесса шифрования
	EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
	cryptedtext_len += len;

	//6. Удаление структуры
	EVP_CIPHER_CTX_free(ctx);
	for (int i = 0; i < cryptedtext_len;i++) {
		cout << hex << cryptedtext[i];
		if ((i+1) % 32 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
	//BIO_dump_fp(stdout, (const char *)cryptedtext, cryptedtext_len - 1);
    //_______________________________________________

	//1. 
	ctx = EVP_CIPHER_CTX_new();
	//2.
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, kluch, iv);
	//3.
	EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len);
	//4.
	int dectypted_len = len;
	EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);

	//5.
	dectypted_len += len;
	EVP_CIPHER_CTX_free(ctx);
	decryptedtext[dectypted_len] = '\0';
	cout << decryptedtext << endl;


	//__________________________________________
	//Шифрование файла производится точно так же,но порциями в цикле
	fstream f0, f_encrypted;
	f0.open("f0.txt", std::fstream::in);
	f_encrypted.open("f_encrypted.txt", std::fstream::out | std::fstream::trunc);
	unsigned int number_of_bites = 0;
	unsigned int filesize = 0;
	char buffer[AES_BLOCK_SIZE] = { 0 };
	char  out_buf[AES_BLOCK_SIZE];
	AES_KEY aes_key;
	AES_set_encrypt_key(kluch, 128, &aes_key);
	while (true) //бесконечный цикл считывания порций файла, шифрования и записи в другой файл
	{
		//считывание
		f_encrypted.read(buffer, AES_BLOCK_SIZE);
		number_of_bites += AES_BLOCK_SIZE;
		//шифрование
		AES_cfb128_encrypt((unsigned char*)buffer,
			(unsigned char *)out_buf,
			AES_BLOCK_SIZE,
			&aes_key, iv, 0, AES_ENCRYPT
			);
	//запись
		f_encrypted.write(out_buf, AES_BLOCK_SIZE);
	
		if (number_of_bites == filesize) break;
	}
	getchar();
	return 0;
}

