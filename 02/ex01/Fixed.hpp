# ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Fixed
{
	private:
		int _value;
		static const int _fractionalBits = 8;

	public:
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		Fixed& operator = (const Fixed& other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

# endif


/*
02/ex01 の目的は、整数だけで小数を表現する「固定小数点数」の仕組みを理解することです。完成コードは出さず、実装に必要な考え方を整理します。
1. _value が保存するもの
小数部のビット数は8なので、倍率は次の値です。
2^8 = 256
_value には実際の数値を256倍した整数を保存します。
実際の値  × 256 = _value
_value ÷ 256 = 実際の値
例：
10.0 → 10 × 256 → _value は 2560
この256が固定小数点のスケールです。ビット演算では 1 << 8 で表せます。
2. 整数コンストラクタ
整数を受け取り、固定小数点形式へ変換します。
考えるべき処理はこれだけです。
受け取った整数 × 256
ビットの観点では、「整数を8ビット左へずらす」と同じ意味です。
なお、_fractionalBits はすでにクラス共通の static const int として8になっています。各コンストラクタで改めて初期化するものではありません。
3. floatコンストラクタ
小数も256倍して保存しますが、結果が小数になる可能性があります。
42.42 × 256 = 10859.52
_value は int なので、そのままでは保存できません。最も近い整数へ丸めます。
10859.52 → 10860
このために roundf を使います。必要なヘッダーは <cmath> です。
単純な整数キャストでは小数部分が切り捨てられ、精度が悪くなるので注意してください。
4. toFloat()
保存値を元の倍率で割ります。
_value ÷ 256
重要なのは、整数同士の割り算にしないことです。どちらかを float として扱わないと小数部分が失われます。
たとえば：
10860 ÷ 256 = 42.421875
元の 42.42 と完全には一致しません。これは8ビットの小数部で表現できる値に丸められるためで、正常です。
5. toInt()
小数部分を取り除き、整数部分だけに戻します。
考え方は：
_value ÷ 256
または、8ビット右へずらします。課題で一般的なのは右シフトです。
2560 → 8ビット右シフト → 10
負数では右シフトと整数除算の丸め方に差が出る可能性がありますが、まずは課題が意図しているビットシフトと固定小数点の関係を理解するのが中心です。
6. operator<<
std::cout << a の左側は std::cout、つまり std::ostream です。そのため、この演算子は通常 Fixed のメンバ関数ではなく、クラス外の関数として用意します。
必要な設計は：
第1引数：出力先の std::ostream を参照で受け取る
第2引数：表示する Fixed をconst参照で受け取る
toFloat() の結果をストリームへ流す
同じストリームを参照で返す
ストリームを返すのは、次のような連結を可能にするためです。
std::cout << a << std::endl
toFloat() がpublicなので、friend にする必要はありません。宣言はクラス定義の後、実装は Fixed.cpp に置けます。
現在のファイルに追加する順番
Fixed.hpp に整数・floatコンストラクタを宣言
toFloat() と toInt() を宣言
クラス外に挿入演算子を宣言
Fixed.cpp に各処理を実装
<cmath> を追加
make して、最初のコンパイルエラーから順に確認
現在の不要な可能性が高いヘッダーは <string>, <fstream>, <sstream> です。ex01では基本的に入出力と丸め処理だけで足ります。
まず Fixed.hpp の宣言部分を自分で追加するところから進めるのがよいです。

1件のメモリ引用MEMORY.md28～30行Used the user preference for hints and incremental explanation without solution code
19:10






まず問題分を日本語で解説してほしい



19:11






この問題文は、ex00で作った Fixed クラスを拡張し、整数や小数を扱えるようにする課題です。
前提
ex00の Fixed クラスは、内部の値 _value を常に 0 で初期化していました。
つまり、固定小数点数を保存する形だけは作りましたが、実際には 0.0 しか表現できませんでした。
ex01では、次の値も扱えるようにします。
整数：10
浮動小数点数：42.42f
Fixed が持つ値を整数やfloatへ戻す
std::cout << fixed で表示する
1. 整数を受け取るコンストラクタ
問題文の
A constructor that takes a constant integer as a parameter.

は、int を受け取って Fixed オブジェクトを作れるようにする、という意味です。
たとえば、mainにある次の処理です。
Fixed const b(10);
ただし、受け取った 10 をそのまま _value に保存するわけではありません。
小数部が8ビットなので、固定小数点形式へ変換して保存する必要があります。
2. floatを受け取るコンストラクタ
問題文の
A constructor that takes a constant floating-point number as a parameter.

は、float を受け取って Fixed オブジェクトを作れるようにする、という意味です。
mainでは次の部分です。
Fixed const c(42.42f);
42.42f も、内部では固定小数点形式の整数に変換して _value に保存します。
f は、この数値がdoubleではなくfloatであることを表します。
3. 小数部は8ビット
問題文の
The fractional bits value should be initialized to 8

は、小数部分を表すために8ビット使う、という意味です。
ex00ですでに次のメンバがあります。
static const int _fractionalBits = 8;
したがって、倍率は次のようになります。
2の8乗 = 256
実際の値を256倍した整数を、内部の _value に保存します。
4. toFloat()
converts the fixed-point value to a floating-point value

内部の固定小数点値を、floatへ戻す関数です。
たとえば、内部では固定小数点形式で保存されている 42.42 を、表示や計算に使える float に戻します。
関数末尾の const は、この関数がオブジェクトの中身を変更しないことを表します。
5. toInt()
converts the fixed-point value to an integer value

内部の固定小数点値を、整数へ戻す関数です。
たとえば、42.42を整数へ変換すると、小数部分を除いた 42 になります。
こちらも末尾に const があるため、オブジェクトの中身を変更しません。
6. << 演算子のオーバーロード
問題文の
An overload of the insertion («) operator

は、次のように Fixed オブジェクトを直接出力できるようにする、という意味です。
std::cout << c;
この << は「挿入演算子」と呼ばれます。
通常の状態では、std::cout は Fixed 型の表示方法を知りません。そのため、Fixed を受け取ったら、その値を浮動小数点表現に変換して出力する処理を追加します。
この課題で最終的にできること
ex01を完成させると、Fixed クラスは次の操作が可能になります。
デフォルト値の 0 から作る
整数から作る
floatから作る
別の Fixed からコピーする
floatへ変換する
intへ変換する
std::coutで表示する
つまり、ex00で作った「入れ物」に、実際の数値を入れたり取り出したりする機能を追加する課題です。

19:11






なるほど、ではまずヘッダーはどう変えたらいいんだ



19:19






11s作業しました



ヘッダーには「実装」ではなく、追加機能の宣言だけを書きます。変更点は3か所です。
1. コンストラクタを2つ追加
デフォルトコンストラクタの近くに、次の引数を受け取るコンストラクタを宣言します。
int const を受け取るもの
float const を受け取るもの
形は次のようになります。
Fixed(int const value);
Fixed(float const value);
引数の型が違うため、同じ Fixed という名前でもコンパイラが適切な方を選びます。これがコンストラクタのオーバーロードです。
2. 変換関数を追加
getRawBits() などと同じpublic領域に、問題文で指定された2つを宣言します。
float toFloat(void) const;
int toInt(void) const;
末尾の const は、「この関数では _value を変更しない」という宣言です。
3. operator<< をクラスの外に追加
これはクラスの閉じ波括弧 }; より後、#endif より前に宣言します。
std::ostream &operator<<(std::ostream &out, Fixed const &fixed);
クラス外に置く理由は、式の左側が Fixed ではなく std::cout だからです。
std::cout << fixed
引数の意味は次のとおりです。
out：出力先。通常は std::cout
fixed：表示する Fixed オブジェクト
戻り値：同じ出力ストリーム。<< std::endlへ処理をつなげるため
なお、現在の <string>、<fstream>、<sstream> はこの課題のヘッダーでは使っていません。<iostream> は std::ostream のために必要です。
ここまで追加したら、次は Fixed.cpp で整数コンストラクタの中身から考える段階です。
*/
