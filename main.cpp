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
//[h]:回到首页
//{gaming}
//[w]:向前移动 [s]:向后移动 [b]:打开背包 [n]:下一页 [u]:上一页

using namespace std;

string map[10][150],x,y,type; //行,列 //尽量只展示30
int r = 0,mapage = 30;//1:ramdom 0:unrandom

int randint(int min,int max) { 
  random_device seed;      //硬件生成随机数种子
  ranlux48 engine(seed()); //利用种子生成随机数引擎
  uniform_int_distribution<> distrib(min, max); //设置随机数范围，并为均匀分布
  int random = distrib(engine);
  return random;
}

void mapout() {
  while(1){
    for (int i = 0; i < 10; i++) {
      if (mapage > 30) {
        for (int j = mapage - 30; j < mapage; j++) {
          if (map[i][j] == "g") cout << "草";
          else if (map[i][j] == "t") cout << "土";
          else if (map[i][j] == "s") cout << "石";
          else if (map[i][j] == "d") cout << "钻";
          else if (map[i][j] == "m") cout << "煤";
          else if (map[i][j] == "i") cout << "铁";
          else if (map[i][j] == "j") cout << "金";
        }
      }
      else {
        for (int j = 0; j < mapage; j++) {
          if (map[i][j] == "g") cout << "草";
          else if (map[i][j] == "t") cout << "土";
          else if (map[i][j] == "s") cout << "石";
          else if (map[i][j] == "d") cout << "钻";
          else if (map[i][j] == "m") cout << "煤";
          else if (map[i][j] == "i") cout << "铁";
          else if (map[i][j] == "j") cout << "金";
        }
      }
      cout << endl;
    }
    cout << "dispayed:" << mapage << " " << "command/keyword:";
    cin >> type;
    if (type == "n") {
      system("clear");
      mapage += 30;
    }
    else if (type == "u") {
      system("clear");
      mapage -= 30;
    }
    else if (type == "h") {
      return 0;
    }
  }
}
int game() {
  if (r == 0) { //创建地图
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 150; j++) {
        if(i <= 1) {
          int sq = randint(0,2);
          if (sq == 0 or sq == 1) {
            map[i][j] = "g";
          }
          else map[i][j] = "t";
        }
        else if(i <= 4) {
          int sq = randint(0,6);
          if (sq == 0 or sq == 1 or sq == 2 or sq == 3 or sq == 5) {
            map[i][j] = "s"; //一切为了好看
          }
          else if (sq == 4) map[i][j] = "m";
          else if (sq == 6) map[i][j] = "i";
        }
        else {
          int sq = randint(0,10);
          if (sq == 0 or sq == 1 or sq == 2 or sq == 3 or sq == 4 or                sq == 5) map[i][j] = "s";
          else if (sq == 6) map[i][j] = "m";
          else if (sq == 7 or sq == 8) map[i][j] = "i";
          else if (sq == 9) map[i][j] = "j";
          else if (sq == 10) map[i][j] = "d";
        }
      }
      
    }
    r = 1;
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
  if (type == "1") {
    system("clear");
    game();
  }
}
int main() { //循环和函数的执行 尽量结构化
  system("clear");
  cout << "𝐕𝐩𝐞𝐫𝐟𝐚𝐜𝐭(AS13379)" << endl;
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
