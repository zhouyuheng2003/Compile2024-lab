#include <cassert>
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

// ���� lexer ������, �Լ� parser ����
// Ϊʲô������ sysy.tab.hpp ��? ��Ϊ��������û�� yyin �Ķ���
// ���, ��Ϊ����ļ����������Լ�д��, ���Ǳ� Bison ���ɳ�����
// ��Ĵ���༭��/IDE �ܿ����Ҳ�������ļ�, Ȼ�����㱨�� (��Ȼ���벻�����)
// ��������ܷ���, ���Ǹɴ�������ֿ����� dirty ��ʵ�ʺ���Ч���ֶ�
extern FILE *yyin;
extern int yyparse(unique_ptr<string> &ast);

int main(int argc, const char *argv[]) {
  // ���������в���. ���Խű�/����ƽ̨Ҫ����ı������ܽ������²���:
  // compiler ģʽ �����ļ� -o ����ļ�
  assert(argc == 5);
  auto mode = argv[1];
  auto input = argv[2];
  auto output = argv[4];

  // �������ļ�, ����ָ�� lexer �ڽ�����ʱ���ȡ����ļ�
  yyin = fopen(input, "r");
  assert(yyin);

  // ���� parser ����, parser �������һ������ lexer ���������ļ���
  unique_ptr<string> ast;
  auto ret = yyparse(ast);
  assert(!ret);

  // ��������õ��� AST, ��ʵ���Ǹ��ַ���
  cout << *ast << endl;
  return 0;
}

