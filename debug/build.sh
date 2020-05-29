if [ ! -d "dist" ]; then
  mkdir dist
fi
flex --outfile=dist/compiler.lex.yy.cpp compiler.l
yacc --output=dist/y.tab.cpp -d compiler.y
cp tree.cpp dist/tree.cpp
cp tree.h dist/tree.h
cd dist
echo '#include"tree.h"\n' | cat - y.tab.hpp > y.tab.hpp.temp && rm y.tab.hpp && mv y.tab.hpp.temp y.tab.hpp
g++ -std=c++11 -o compiler tree.cpp compiler.lex.yy.cpp y.tab.cpp

