//
//  main.cpp
//  List of Conquests
//
//  Created by Tina Tsai on 2017/7/3.
//  Copyright © 2017年 Tina Tsai. All rights reserved.
//
/*
 原文網址
http://garbagecode.blogspot.tw/2016/05/uva-10420-list-of-conquests.html
 這一題的code非常短
 但是有不少需要說明的地方
 
 首先解釋 scanf(" %s%*[^\n]", ...)
 空白代表吃掉所有前面的 空白字元(包含換行和tab)
 %s 代表一直讀入 直到遇到第一個空白字元
 %[^\n] 代表一直讀入 直到遇到第一個換行字元
 那個 * 代表我們後面並沒有要用一個變數 把%[^\n]讀到的東西存下來
 不過要注意的是遇到 空行 %[^\n] 會匹配失敗
 (程式還是正常運行就是)
 但你的字串變數 會保持原狀!!! 而不是變成空字串
 這一點要注意~
 接著講解 map
 map 裡會存著許多的 <key,value> pair
 我們可以用 .frist 讀取存在map裡的物件的 key
 用 .second 讀取存在map裡的物件的 value
 用 map[x] 來讀取/修改 以x為key的物件 的 value
 
 
 這會讓obj 跑過所有在 container裡的物件
 這是個 C++ 11 新引入的 非常簡潔有力的寫法
 */
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

char country_name[100];
map<string, int> countries;

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int ni = 0; ni < n; ni++)    //有幾個人
    {
        scanf(" %s%*[^\n]", country_name);
        //%s一直讀入直到遇到第一個空白 %s=國家
        //%*[^\n]" 一直讀入直到遇到地一個換行字元 %*[$\n]= 姓名
        //後面,country_name >>> %s=country_name
        countries[string(country_name)]++;
        //countries[ string(char)];
    }
    
    for(auto country:countries)  //for(auto obj:container)  range-based for loop
        //country 跑過 所有在 countries裡的物件
        printf("%s %d\n", country.first.c_str(), country.second);
}
