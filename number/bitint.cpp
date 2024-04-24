class BigInt
{
private:
    std::vector<int> digits;

public:
    // Constructors
    BigInt() {}
    BigInt(int num)
    {
        while (num > 0)
        {
            digits.push_back(num % 10);
            num /= 10;
        }
    }
    BigInt(const std::string &str)
    {
        for (int i = str.length() - 1; i >= 0; --i)
        {
            digits.push_back(str[i] - '0');
        }
    }
    bool operator<(const BigInt &other) const
    {
        if (digits.size() != other.digits.size())
            return digits.size() < other.digits.size();
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            if (digits[i] != other.digits[i])
                return digits[i] < other.digits[i];
        }
        return false; // Equal
    }
    // Addition
    BigInt operator+(const BigInt &other) const
    {
        BigInt result;
        int carry = 0;
        int maxSize = std::max(digits.size(), other.digits.size());
        for (int i = 0; i < maxSize || carry; ++i)
        {
            if (i == result.digits.size())
                result.digits.push_back(0);
            result.digits[i] += carry + (i < digits.size() ? digits[i] : 0) + (i < other.digits.size() ? other.digits[i] : 0);
            carry = result.digits[i] / 10;
            result.digits[i] %= 10;
        }
        return result;
    }
    BigInt operator*(const BigInt &other) const
    {
        BigInt result;
        result.digits.resize(digits.size() + other.digits.size(), 0);

        for (size_t i = 0; i < digits.size(); ++i)
        {
            int carry = 0;
            for (size_t j = 0; j < other.digits.size() || carry; ++j)
            {
                int product = result.digits[i + j] + digits[i] * (j < other.digits.size() ? other.digits[j] : 0) + carry;
                result.digits[i + j] = product % 10;
                carry = product / 10;
            }
        }

        // Remove leading zeros
        while (result.digits.size() > 1 && result.digits.back() == 0)
            result.digits.pop_back();

        return result;
    }
    // Conversion to string
    std::string toString() const
    {
        if (digits.empty() || (digits.size() == 1 && digits[0] == 0))
            return "0";

        std::string result;
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            result += char(digits[i] + '0');
        }
        return result;
    }
    // Overload << for cout
    friend std::ostream &operator<<(std::ostream &os, const BigInt &bigInt)
    {
        os << bigInt.toString();
        return os;
    }
};