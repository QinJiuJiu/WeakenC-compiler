int factorial(int i) {
    if (i <= 1) {
        return 1;
    }
    else{
        return i * factorial(i - 1);
    }
}
int main() {
    int i, times, result;
    times=read();
    for(i = 1; i < times + 1; i++)
    {
        int temp;
		temp = read();
		result = factorial(temp);
        print(result);
	}
}