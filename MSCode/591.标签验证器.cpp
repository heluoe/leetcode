/*
 * @lc app=leetcode.cn id=591 lang=cpp
 *
 * [591] 标签验证器
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string code)
    {
        if (code.empty())
            return false;
        regex e(R"(<!\[CDATA\[.*?\]\]>)");
        regex tag(R"(<\s*\/?\s*([^>]*?["][^"]*["])*[^>"]*>)");

        // cout << code << ", " << code.length() << endl;
        // "<B></B>"\n minlength = 7
        if (code.length() < 7 || code[0] != '<' || code[1] == '!')
            return false;

        code = regex_replace(code, e, "xxx");
        smatch sm;
        stack<string> close_stack;

        regex re_vaild(R"([A-Z]{1,9})");
        while (regex_search(code, sm, tag))
        {
            string tag = sm.str(0);
            tag = tag.substr(1, tag.length() - 2);
            if (tag[0] == '/')
            {
                if (close_stack.empty() || close_stack.top() != tag.substr(1))
                    return false;

                close_stack.pop();

                if (close_stack.empty() && !sm.suffix().str().empty())
                    return false;
            }
            else
            {
                close_stack.push(tag);
                if (!regex_match(tag, re_vaild))
                    return false;
            }
            // rest of string
            code = sm.suffix().str();
            // cout << tag << ", " << sm.position(0) << ": " << code << endl;
        }

        return close_stack.empty() && code.empty();
    }
};
// @lc code=end

// "<TAG>sometext</TAG><![CDATA[ABC]]>"

// "< asdfsf sadfsf <H></H>"\n
// "<![CDATA[ABC]]><TAG>sometext</TAG>"

// "<DIV>This is the first line <![CDATA[<div>]]></DIV>"
// "<012312asdf></012312asdf>0"\n
// "<>asdfasdf</>"\n
// "<![CDATA[wahaha]]]>asdfasfd<![CDATA[]> wahaha]]>"

// "<![CDATA[wahaha]]]><![CDATA[]> wahaha]]>asdfasfd"\n
// "<B><![CDATA[wahaha]]]>asdfasfd</B><DIV><![CDATA[<div>]]></DIV>"\n
// "<C><B><![CDATA[wahaha]]]>asdfasfd</B><DIV><![CDATA[<div>]]></DIV></C>"\n
// "<DIV>This is the first line <![CDATA[<div>]]></DIV>"\n
// "asdfs<B></B>"\n
// "<AAAAAAAAAA></AAAAAAAAAA>"\n
// "<DIV>This is the first line <![CDATA[<div>]]></DIV>"\n
// "<  ASASD>asdfasdf</  ASASD>"\n
// "<DIV> unmatched tags with invalid tag name  </1234567890> and <!CDATA[[]]>  </DIV>"\n
// "<DIV> unmatched tags with invalid tag name  and <![CDATA[]]>  </DIV>"\n
// "<DIV>  unmatched <  </DIV>"\n
// "<DIV>  unmatched start tag <B>  and unmatched end tag </B>  </DIV>"\n
// "<DIV>This is the first line <![CDATA[<div>]]><DIV>"