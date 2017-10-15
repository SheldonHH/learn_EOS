```C++
class R{
    int w, h;
	public:
  		R(int x, int y) : w(x), h(y){};
  		R() = default;
  		R(const R& other) = delete;
  		int area(){
            return w*h;
        }
};

```

