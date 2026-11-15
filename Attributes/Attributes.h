#pragma once

class Price{
    private:
    int value_;
    public:
    explicit Price(int val);
    int getValue() const;
    void setValue(int newVal);
};

class Quantity{
    private:
    int value_;
    public:
    explicit Quantity(int val);
    int getValue() const;
    void change(int delta);
};
