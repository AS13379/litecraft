#include <iostream>
#include <unistd.h>
#include <random>
#include <thread>
#include <iomanip>

//  _      _ _                       __ _
// | |    (_) |                     / _| |
// | |     _| |_ ___  ___ _ __ __ _| |_| |_
// | |    | | __/ _ \/ __| "__/ _` |  _| __|
// | |____| | ||  __/ (__| | | (_| | | | |_
// |______|_|\__\___|\___|_|  \__,_|_|  \__|
// 此程序由@AS13379制作，下面是一些参数的声明
// g:草 t:土 s:石头 d:钻石 m:煤 i:铁 j:金
// 二次创作时避免使用单字母变量以及i,j等常用单词
//标准分割为25个=,次级分割为20个,递减.缩进为2个空格
//{mode}
//[h]:回到首页 [e]:退出
//{gaming}
//[w]:向前移动 [s]:向后移动 [b]:打开背包

using namespace std;

string map[10][10],x,y; //行,列
int r = 0,type;//1:ramdom 0:unrandom

int randint(int min,int max) { 
  random_device seed;      //硬件生成随机数种子
  ranlux48 engine(seed()); //利用种子生成随机数引擎
  uniform_int_distribution<> distrib(min, max); //设置随机数范围，并为均匀分布
  int random = distrib(engine);
  return random;
}

void mapout() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      
      cout << map[i][j];
    }
    cout << endl;
  }
}
int game() {
  if (r == 0) { //创建地图
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 19; j++) {
        if(i <= 1) {
          int sq = randint(0,1);
          if (sq == 0) {
            map[i][j] = "g";
          }
          else map[i][j] = "t";
        }
        else if(i <= 4) {
          int sq = randint(0,2);
          if (sq == 0) map[i][j] = "s";
          else if (sq == 1) map[i][j] = "m";
          else if (sq == 2) map[i][j] = "i";
        }
        else {
          int sq = randint(0,4);
          if (sq == 0) map[i][j] = "s";
          else if (sq == 1) map[i][j] = "m";
          else if (sq == 2) map[i][j] = "i";
          else if (sq == 3) map[i][j] = "j";
          else if (sq == 4) map[i][j] = "d";
        }
      }
      
    }
  }
  mapout();
  return 0;
}

void home() {
  cout << "=========================" << endl;
  cout << "1.开始游玩" << endl;
  cout << "  [首次使用会自动创建新的存档]" << endl;
  cout << "2.帮助文件" << endl;
  cout << "3.关于" << endl;
  cout << "=========================" << endl;
  cout << "command/keyword:";
  cin >> type;
  if (type == 1) {
    system("clear");
    game();
  }
}
int main() { //循环和函数的执行 尽量结构化
  system("clear");
  cout << "𝐕𝐩𝐞𝐫𝐟𝐚𝐜𝐭(AS13379)" << endl;
  sleep(2);
  system("clear");
  cout << "𝔾𝕚𝕥ℍ𝕦𝕓" << endl;
  sleep(2);
  system("clear");
  cout << " ︿︿︿︿︿︿︿︿︿︿︿︿︿︿" << endl;
  cout << "⟨ 🄻  🄸  🅃  🄴  🄲  🅁  🄰  🄵  🅃  ⟩" << endl;
  cout << " ﹀﹀﹀﹀﹀﹀﹀﹀﹀﹀﹀﹀﹀﹀" << endl;
  sleep(2);
  system("clear");
  cout << "=====欢迎来到litecraft!======" << endl;
  sleep(1);
  system("clear");
  home();
  return 0;
}
