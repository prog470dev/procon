/* 引数の大小関係は考えなくて良い */

//最小公倍数
ll gcd( ll a, ll b){
  if(b == 0){
    return a;
  }
  return gcd(b, a % b);
}

//最大公約数
ll lcm( ll a, ll b )
{
	return a / gcd(a, b) * b;
}
