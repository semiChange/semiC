// 结构体

// 声明
struct Stu {
  char name[];
  int age;
};

// 定义
struct Stu s1;


// 声明+定义
struct Stu {
  char name[];
  int age;
} s1,s2;


// 定义时初始化
struct Stu s1 = {"张三",17};
printf("%s %d",s1.name,s1.age);

// 结构图指针
struct Stu *p = &s1;
printf("%s",p->name);

// 简写
typedef struct {
  int x;
  int y;
} Point;
Point p1;  // 这样使用,就像类, 方便

