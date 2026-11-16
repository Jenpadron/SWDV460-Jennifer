all:
    g++ main.cpp -o books -ltinyxml2
clean:
    rm -f books
