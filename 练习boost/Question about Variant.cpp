int main(){


	class DoubleVisitor: public boost::static_visitor<>{
	public:
		void operator(int& i)
	}
}


class DoubleVisitor:public boost::static_visitor<>{
	public:
		void operator(int& i){
			i += i;
		}
		void operator(string& s){
			s + s;
		}
};


DoubleVisitor f;
vector< boost::variant<int i, string s> >v; //为了和union{}区分开来，使用<>
v.push_back("fsd");

for(auto x: v){
	boost::apply_visitor(f, x); 
}

