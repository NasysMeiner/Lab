//#include <fstream>
//#include <string.h> //  memcpy
//#include <string>
//#include <iostream>
//
//namespace Bitmap
//{
//#   pragma pack( push, 1 )
//    struct Header
//    {
//        unsigned short bitmap;
//        unsigned int fileSizeLow;
//        unsigned int fileSizeHigh;
//        unsigned int headerSize;
//        unsigned int unknown2;
//        unsigned int width;
//        unsigned int height;
//        unsigned short unknown3;
//        unsigned short depth;
//        unsigned int unknown4;
//        unsigned int bitmapSize;
//        unsigned int unknown5;
//        unsigned int unknown6;
//        unsigned int unknown7;
//        unsigned int unknown8;
//    };
//#   pragma pack( pop )
//}
//
//bool rotateImage90ClockWise(std::string inFileName, std::string outFileName);
//
//bool rotateImage90ClockWise(std::string inFileName, std::string outFileName)
//{
//    std::ifstream in(inFileName.c_str(), std::ios::in | std::ios::binary);
//    if (not in.is_open()) {
//        return false;
//    }
//    Bitmap::Header hdrIn;
//    //  Читаем заголовок из входного файла
//    in.read(reinterpret_cast<char*>(&hdrIn), sizeof(Bitmap::Header));
//
//    //  Работаем только с RGB_888 файлами
//    if (hdrIn.depth != 24) {
//        in.close();
//        return false;
//    }
//
//    //  Копируем заголовок входного файла в заголовок выходного файла
//    Bitmap::Header hdrOut;
//    memcpy(&hdrOut, &hdrIn, sizeof(Bitmap::Header));
//    //  Переворачиваем картинку
//    hdrOut.width = hdrIn.height;
//    hdrOut.height = hdrIn.width;
//    //  Вычисляем новую длину строки с учетом выравнивания
//    unsigned rowLength = hdrOut.width * hdrOut.depth / 8 + hdrOut.width % 4;
//    //  Вычисляем новый размер изображения
//    hdrOut.bitmapSize = rowLength * hdrOut.height;
//    //  Устанавливаем новый размер файла
//    hdrOut.fileSizeLow = hdrOut.bitmapSize + hdrOut.headerSize;
//
//    //  Создаем массив для хранения преобразованного изображения
//    char* dataOut = new char[hdrOut.bitmapSize];
//    //  А сюда будем читать каждый пиксель из входного файла
//    char color[3];
//
//    /*std::cin >> hdrIn.height;
//    std::cin >> hdrIn.width;*/
//
//    for (unsigned i = 0; i < hdrIn.height; ++i) {
//        for (unsigned j = 0; j < hdrIn.width; ++j) {
//            //  Читаем пиксель
//            in.read(color, sizeof(color));
//            //  Копируем по нужному адресу в выходное изображение
//            memcpy(&dataOut[(hdrOut.height - j - 1) * rowLength + i * 3],
//                color, sizeof(color));
//        }
//        //  Пропускаем лишние байты
//        if (int overHead = hdrIn.width % 4) {
//            in.seekg(overHead, std::ios::cur);
//        }
//    }
//
//    std::ofstream out(outFileName.c_str(), std::ios::out | std::ios::binary);
//    if (not out.is_open()) {
//        in.close();
//        return false;
//    }
//
//    out.write(reinterpret_cast<char*>(&hdrOut), sizeof(Bitmap::Header));
//    out.write(dataOut, hdrOut.bitmapSize);
//    out.close();
//    in.close();
//
//    return true;
//}
//
//int main() {
//    std::string name = "bmpfile.bmp";
//    bool act = rotateImage90ClockWise(name, "1");
//
//    /*std::cin >> act;*/
//
//    return 0;
//}

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <string.h> //  memcpy
#include <string>
#include <iostream>

struct RGB
{
    BYTE    rgbtBlue;
    BYTE    rgbtGreen;
    BYTE    rgbtRed;
} p[1152 * 648];

void main()
{
    FILE* f1, * f2;
    BITMAPFILEHEADER bmfh;
    BITMAPINFOHEADER bmih;
    RGBTRIPLE RGBColor;

    f1 = fopen("bmpfile.bmp", "r+b");
    fread(&bmfh, sizeof(bmfh), 1, f1); 
    fread(&bmih, sizeof(bmih), 1, f1);
    int h, w;
    w = bmih.biWidth;
    h = bmih.biHeight;

    f2 = fopen("2.bmp", "w+b");
    bmih.biWidth = h;
    bmih.biHeight = w;
    fwrite(&bmfh, sizeof(bmfh), 1, f2);
    fwrite(&bmih, sizeof(bmih), 1, f2);

    int k = 0, j = w;
    for (int i = 0; i < bmih.biHeight * bmih.biWidth; i++)
    {
        fread(&RGBColor, sizeof(RGBColor), 1, f1);
        p[i].rgbtBlue = RGBColor.rgbtBlue;
        p[i].rgbtGreen = RGBColor.rgbtGreen;
        p[i].rgbtRed = RGBColor.rgbtRed;
    }

    for (int i = 0; i < bmih.biHeight * bmih.biWidth; i++)
    {
        if (i != 0 && i % h == 0)
        {
            k = 0;
            j--;
        }

        fwrite(&p[(h * w) - (k * w) - j], sizeof(RGB), 1, f2);
        k++;
    }

    /*for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            fread(&RGBColor, sizeof(RGBColor), 1, f1);
            p[i][j].rgbtBlue = RGBColor.rgbtBlue;
            p[i][j].rgbtGreen = RGBColor.rgbtGreen;
            p[i][j].rgbtRed = RGBColor.rgbtRed;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            fwrite(p[1], sizeof(RGB), 1, f2);           
        }
    }*/
    
    fclose(f1);
    fclose(f2);
}
