struct fenwick{
	vector<int> fen;
	int max_n;
	void setup(int _ = 100003){
		max_n = _;
		fen.assign(_ + 1, 0);
	}
	void upd(int _, int _val){
	    for(int i = _; i <= max_n; i += i & -i)
	        fen[i] += _val;
	}
	int sum(int _) {
	    int _res = 0;
	    for(int i = _; i; i -= i & -i)
	        _res += fen[i];
	    return _res;
	}
	int ran(int _x, int _y){
		return sum(_y) - sum(_x - 1);
	}
} fw;
