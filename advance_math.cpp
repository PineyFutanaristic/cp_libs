struct advance_math{
	vector<int> _f, _fi;
	int max_n, _mod;
	int fp(int _x,int _y) {
		int _res = 1;
		while(_y){
			if(_y&1) _res = _res*_x%_mod;
			_x = _x*_x%_mod;
			_y >>= 1;
		}
		return _res;
	}
	int add(int _x, int _y){
		int _res = (_x + _y)%_mod;
		return (_res < 0 ? _res + _mod : _res);
	}
	int inv(int _){
		return fp(_, _mod - 2);
	}
	int mul(int _x, int _y){
		int _res = (_x * _y)%_mod;
		return (_res < 0 ? _res + _mod : _res);
	}
	void setup(int _ = 100003,int _m = 1000000007){
		_mod = _m;
		max_n = _;
		_f.assign(max_n + 1, 0);
		_fi.assign(max_n + 1, 0);
		_f[0] = 1;
		for(int i = 1 ; i <= max_n ; i ++) _f[i] = (_f[i - 1] * i)%_mod;
		_fi[max_n] = inv(_f[max_n]);
		for(int i = max_n - 1; i >= 0 ; i --) _fi[i] = (_fi[i + 1] * (i + 1))%_mod;
	}
	int C(int _x, int _y){
		if(_x > _y) return 0;
		return mul(_f[_y], mul(_fi[_x], _fi[_y - _x]));
	}
	int P(int _x, int _y){
		return mul(_f[_y], _fi[_y - _x]);
	}
	int CK(int _x, int _y){
		return C(_y - 1, _x + _y - 1);
	}
} mt;
