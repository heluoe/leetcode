#include <string>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=1371 lang=cpp
 *
 * [1371] 每个元音包含偶数次的最长子字符串
 */

// @lc code=start
class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        int maxlen = 0;
        int dp[2][2][2][2][2];
        std::memset(dp, -1, sizeof(dp));
        dp[0][0][0][0][0] = 0;
        int j = 1;
        int a, e, i, o, u;
        a = e = i = o = u = 0;
        for (const auto &c : s)
        {
            if (c == 'a')
                a ^= 1;
            if (c == 'e')
                e ^= 1;
            if (c == 'i')
                i ^= 1;
            if (c == 'o')
                o ^= 1;
            if (c == 'u')
                u ^= 1;
            if (dp[a][e][i][o][u] != -1)
                maxlen = std::max(j - dp[a][e][i][o][u], maxlen);
            else
            {
                dp[a][e][i][o][u] = j;
            }

            j++;
        }
        return maxlen;
    }

    int findTheLongestSubstringTimeOut(string s)
    {
        int maxlen = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            std::unordered_map<char, int> map_vowel = {{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
            map_vowel[s[i]] = 1;
            maxlen = std::max(maxlen, isVowel(map_vowel) ? 1 : 0);
            for (int j = i + 1; j < s.length(); ++j)
            {
                if (map_vowel.find(s[j]) != map_vowel.end())
                    map_vowel[s[j]]++;
                else
                {
                    map_vowel[s[j]] = 1;
                }

                if (isVowel(map_vowel))
                    maxlen = std::max(maxlen, j - i + 1);
            }
        }
        return maxlen;
    }
    bool isVowel(const std::unordered_map<char, int> &map_vowel)
    {
        if (map_vowel.at('a') % 2 == 0 && map_vowel.at('e') % 2 == 0 && map_vowel.at('i') % 2 == 0 && map_vowel.at('o') % 2 == 0 && map_vowel.at('u') % 2 == 0)
            return true;
        else
        {
            return false;
        }
    }
};
// @lc code=end

/*
"id"
"a"
"lffjsdhuyanjfesetkrgdkvpgjtwzbwtgfkvqggundksswifayuwwqjmrmmckkeiitofogmpcyowdrfijnjxzjgluwevtygrudzngiyrrvuhevzsvczkbxyoiuwbvbthbxlcfvfggzutbqttwuqavnpyubrhqhvdknfbqtmjlaokmopplxufnbvwqkisbamepgmrtxofhqbtfnoxsuxagbstmcwqmaezhwmkgdumkbtcgllwbunsjnjuqfxfzqsevwasangzhodanfrjqxoxvfztsmgzzwjkdudrdpbzrmlrbdoibskxoejobejrdzsducnnqcnlrsfwsppwuwtqynjyoohgszrgebixayoovfgjrjecfqcvffnfgynzikyverhnkxyayyxxhfujbdhtvansaqbfvztazroxxnuelmhyvspwruidqxjajuqybjbclldvqoiwbbriklhyizpiyychnmpftnonhoyqucxqmmggtebueollzzvzdihkjavinoiukzwwcwxainwehtltmyahrwxfhvdgdgxuhbnxkexvaoutgbtzbwydbglcmstgvkmjftjjislhhdxmeljltqslbqbcnkqlrhjqjmqrkferdvtevhwjnniqutzvuljoobornasdjtqfucdhlolvjeiyvdxezvpkrhlbbdfpovqcmbsxecjautohtzxhgwersmesweflvblaxvvpocbwwozemuiybbqbfhtxjqdysjfbsdpeyidrzcvkezhhksozlsywvascxisrfaxruyltjrfuaprflszqlwyrnpplndvcdzhzkgbwztswbslhyytznmbvbnyzxsyivslwcdkflmofxfnwpgaqxfgvufvctxxttacgoibzminxhodcgggafnupokfvgncmwllcqvoqvrwagillaghnklvtoowxxdxrybugykcniwvyhbjdjseznlqczjcopfhsaragzgktcsmnqzumvskmojqlgerujrdxplmwfvbcpvbmesxefqcxmrgqmylwsnfnsihyxsltqazzywjjqyiegyobzyidxvcbuucpepotmhvbnfbjobequugguwfgeamuaymtllkekkrwkubkoyyfcaxapvdgmtqntdiqnbzyogbrawxjncklsmbtviegafobtsznwdrbqfwuvuocaraeharbqusvhtwnwdplkfxvghcugfwjccwgexcoyyilhefsyhnclqrfybyrvbiarxspngszdlwkqqsxtyvyifxsjzjpqkqutndbccjtnumlkscwersxoqnhrzixnkujfbdxdodxpywlidkmdfqxroxzqcpksdkdydrhphpkbfbanvkjrtxhlevyxycugybfyywlnvigfgmyqffhoettytyjskfvkrstjhzgfjbeeanblwoengfrlxfxcwilkbqjvextpubzouyntcaaybaayglgobwbhjgryfgsglrgxeswdkfrzuovparpcaoksllnewddovzkfucmaqoavytejzijbppbsezaptnbhdxmvrqasjaahqwumiulxagtxngxoqybezrtiubdmdbptpedwpifbdrocfkoyrfwpxliwyjpfvjqafhdxmcdjzzwdivhfyvldodkqrcosncqtdotpimopmmdmkzuwacfpnacxmvqtkbyaquaoxqfojwncqxtgnkpynumvuaswxqurdfymrzeigpxekxxrudftwuzpajbvrdipxfniljkifqsgttrdtfidgbvveqyusyvuxvoxurdrryhfnntyfbkwzakywfelhvsbwzxnufksguhpjisuqqwsyqphyyfwcshoemfawdxbbrbtpyoxapijixmpdcjumnghqecwwxjgzdlyiehllfxyddxgjhucbktxmgltvwcyookvjkvyqaqcefaahgywvxxnjufdmqqatgcgfkgyzxkzhilmwkbogyvdoemmgkkhpomxaoluupkbomvtwsvppwvjbqohcujufogifrjxmagstpajuxyizricymbsrwbgwpygmkjptqiwzitfmmpzrhhntocwymbawglgdwbpgbvfkbvqiggznqcsfibeawyzbsrgxfkefwmsyaaskquyagcyxpocfiqaznjsrsgfkdxsjwjgsqdaiggyhrgpkmztpxdlcoipxbakpwahrebmdhbjtlddiixehrxtepbnowaakunjpbxoknuafilhcetwkmrrswjyqyklzpetgngdycfauacoqscflqzruffxncodapyulmxeslethmkgzqyurdjogsvoeibfgwprgbmulpqnhgyucaezptwgpimdqcdlfgvnjniyquhmnbbxxglmkyniowmfewnlwvlsylqnblydkbgxtlfrysxjprfnllafftlzwwpuovrgdkuxanhojnicrgodubywaryshhbtpvkggdawyjuiwdelonkzywbqjcohfsssgqjysuspjvidruiffqxtfnwjmmhfnfrrkhgyejwvcucwhdujyaemmubdtbeomjhfphushtiqynzosswjeuvqzebeuresaqirrfwblprztfhkuyufwgvfzspvxhegbqkzhmowiwfdbcbjpbdujztlzlhgigfkivxklbcgfmuogtaommlvlpttauixczvbmnlzwmfjugytcjanboamgrtpziatwxghvueytwkzhuikbmjauoanadfvhamtoeycggynsswllcxzhgdetilwxkninlvhcozhuiuaqtkglsvjlwgvlkrrincmgxoxsggkpoabjeqmcjrsekkmpuvseihhmwslttrxbjoqwluaeppyabmuwnxdgvnxlnomncpfqvgfdxnzlhfmwslwtlervfzzhirhuzczcgsnpybkhcnckfzphlxssgzjfoyxydvadirjzdxjgoxhxanyckoooruhnimtcsmvmddlyllmppgugzezgdxaswfpkijcgywtyrezviwhdsyjqnksrleqoqhukgrxkeremwjbawbnlbqosxvouqjrmmvykipcazekculbbumkgenhjkahgimjpmpytoyiaoooqnxztgtlunffvszorltqagxdlxbuwockudcqlhwckehlhihqmsbaiyxipdpvnidblplrtignxmfsyulcrojpxlgkmylfolirxehxfkvwadegerqbmyeekpodamemcxtecqijesxxkvwdsocqyuagqylwodgaszazvrdjuvanurfrttixfbasggfxwdulbvwvvjdtfgabhfnsheaqopbepiorywlsktvonhxloppagkgdkobywfivrhowneyfszbqskpxvwjriiqqmhqhkjisksmihttcupfzyylrvsfrtcopvlkcrqghvwelkrqqrffuygsggrbsungonkvakfehnrpfqddsdatofcrcewanzigluouypzotpousidkkcosvmimkcjeiuvaefftmdhmfwjltqemdtmlhadgwymcasllmdetyfggohqfoiphmaadfbhkkdnpeubislwgrkpejxjalpaytzhhbrvrjfpjrcgdfsakeqxexbgfhevhruhhwxsjqtnhxsemsvvxsyevfmmqevdsqergvfphpckbpeoeqyrmmdzafgtshitmibbpoucyynengtaaixahewgvpsiufqxgilmtazymycrxnjajdgpdluhvtftaummsbfureuiptxmedlxothitffouogmucgwznfobcbveengtmqdknzvzzysmjwgnbbykimpjckyzsebcbfpknxbodxpigmfnhxlmywdwptmkzuxxuvhbcixbsgngrtxgbcjuyctaqvzayvzeofbubuyhhgraohnhuelbqrlnbzlxahpsmgwpiflujdazsqrmrmtssudexfiulbyzjgmuucobevbeeofefsekshtdlidbfdbtywhbjerawvfobnadfcbzbkptozixprdqzvrzthhjyrnpajyswpogxvmefzfckgpwadkxzaqktvhzegtqlgxkfynowfmllyjigzldltvwfxseifqqishhuoguviviuvpkfljauaqtmynjwleevsdcsstcydfhlbhlnnyriomuzaxrvwlyyowsmclsudlojdnyjzvpnoegzltxgmeqkbfqdcutwgaupzkpnftkxhbyjcabavxohtkktkdejziuyzrctmkpukfsjbjznarrtgeyvdxrsoyikddlnxuonmbtrkadgmhwjpnvlmoonczsjpjpcevcdvuxqmyfylyfcnqahzynsfqcobglkdehuapfpjgsiztsiobjkcpopbloplalgwzeccjnnkivvqvidmhxcpzefrqrlhjcyyfolyzogmbjiakufyjytmjgjwylwpjvixougyggjmbzarudlmlyhvcxbhuqurxlznwkkrjbyiioumtsmybrtzvibqyvhibxmvgkoiyzmjdrq"
*/
