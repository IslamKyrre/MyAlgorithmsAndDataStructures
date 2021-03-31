class C {
public:
    double re, im;

    double abs() {
        return sqrt(re * re + im * im);
    }

    C() : re(0), im(0) {};

    C(double re, double im) : re(re), im(im) {};

    explicit C(double re) : re(re), im(0) {};

    C(const C &x) {
        re = x.re;
        im = x.im;
    }

};

C operator+(const C &a, const C &b) {
    C sum = C(a.re + b.re, a.im + b.im);
    return sum;
}

C operator-(const C &a, const C &b) {
    C sub = C(a.re - b.re, a.im - b.im);
    return sub;
}

C operator*(const C &a, const C &b) {
    C mul = C(a.re * b.re - a.im * b.im, a.im * b.re + a.re * b.im);
    return mul;
}

C operator/(const C &a, const C &b) {
    C div = C((a.re * b.re + a.im * b.im) / (b.re * b.re + b.im * b.im),
              (a.im * b.re - a.re * b.im) / (b.re * b.re + b.im * b.im));
    return div;
}

bool operator==(const C &a, const C &b) {
    return a.re == b.re && a.im == b.im;
}

bool operator!=(const C &a, const C &b) {
    return !(a == b);
}

/****************/

C operator+(const double &aa, const C &b) {
    C a = C(aa);
    return a + b;
}

C operator+(const C &a, const double &bb) {
    C b = C(bb);
    return a + b;
}

C operator-(const double &aa, const C &b) {
    C a = C(aa);
    return a - b;
}

C operator-(const C &a, const double &bb) {
    C b = C(bb);
    return a - b;
}

C operator*(const double &aa, const C &b) {
    C a = C(aa);
    return a * b;
}

C operator*(const C &a, const double &bb) {
    C b = C(bb);
    return a * b;
}

C operator/(const double &aa, const C &b) {
    C a = C(aa);
    return a / b;
}

C operator/(const C &a, const double &bb) {
    C b = C(bb);
    return a / b;
}

bool operator==(const double &aa, const C &b) {
    C a = C(aa);
    return a == b;
}

bool operator==(const C &a, const double &bb) {
    C b = C(bb);
    return a == b;
}

bool operator!=(const double &aa, const C &b) {
    C a = C(aa);
    return a != b;
}

bool operator!=(const C &a, const double &bb) {
    C b = C(bb);
    return a != b;
}

/*****/

ostream &operator<<(ostream &out, const C &x) {
    cout << x.re << " " << x.im << endl;
    return out;
}