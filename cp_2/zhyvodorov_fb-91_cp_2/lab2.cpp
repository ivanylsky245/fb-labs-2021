﻿#include <iostream>
#include <vector>
#include <map>

using namespace std;
string Alphabet = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
map <char, int> index;
map <int, char> letter;
map <char, int> number;
map <int, char> numberBack;
float IndexFinde(string text, int key)
{
    float n = text.size() * (text.size() - 1);
    float IndVid = 0;
    for (int i = 0; i < text.size(); i++)
    {
        number.find(text[i])->second++;
    }
    for (int i = 0; i < Alphabet.size(); i++)
    {
        IndVid += float((number.find(Alphabet[i])->second * (number.find(Alphabet[i])->second - 1))) / n;
        number.find(Alphabet[i])->second = 0;
    }
    return IndVid;
}

string Sippher(string text, string key)
{
    for (int i = 0; i < text.size(); i++)
    {
        int a = (index.find(text[i])->second + index.find(key[i % key.size()])->second) % Alphabet.size();
        text[i] = letter.find(a)->second;
    }
    return text;
}
void Task1()
{
    string ytext = "атлантическоепобережьезападнойсахарызанятоаккумулятивнойприморскойнизменностьюпереходящейнавостокеввозвышенныецокольныеравнинысостанцовымимассивамиасеверовостокзаходятотрогиступенчатогоплатодраавысотойдомразвеваемыепескиидюнызанимаютзначительныеплощадивзападнойсахареважнейшимиполезнымиископаемымиявляютсяфосфоритыатакжежелезныерудыинефтьнашельфеклиматтропическийпустынныйжаркийвовнутреннихрайонахиболеемягкийнапобережьезасчетвлиянияхолодногоканарскоготеченияэпизодическиеосадкивыпадаютвеснойиосеньюммвгодсильныеветрарегулярноподнимаютпыльныебурипостоянныхреквзападнойсахаренетавременныеводотокимногочисленнывовремядождейсабалерасагияэльхамраэльфушбедныйразреженныйрастительныйпокровпредставленпустыннойрастительностьюгалофитамисолянкисарсазанистелющимисязлакамианапобережьемолочаямивоазисахинизовьяхуэдовзанимающихтерриториипроизрастаютпальмыиакацииивыращиваютсязерновыекультурыпшеницапшеноячменьфруктыовощифиникикочевыеплеменаразводятсвышетысячголовскотакозыовцыверблюдыкоторыепочтисвелинанетибезтогоскуднуюрастительностьврезультатеисчезлинескольковидовгазелейантилопаддаксидругиедикиеживотныеизкопытныхещевстречаютсягазельдоркасизхищныхшакалгиеналисицафенекнапобережьерасполагаютсякрупныеколонииперелетныхкуликовиместаотдыхарозовыхфламинговприбрежныхводахежегодновылавливаетсяоколотысячтоннрыбымеждународноепризнаниесадрзападнаясахаранеприспособленадляоседлогосельскогохозяйстваиззажаркогозасушливогоклиматаикаменистойпесчанойпочвытемнеменеекочующиепастухиразводятовецкозиверблюдовнатерриториизападнойсахарыимеютсябогатыезалежифосфатовособенновбукраразработкаместорожденийначаласьвначалегодов";
    string ykey = "да";
    cout<< "Индекс соответсвия шифртекста с ключем "<< ykey.size() << " = " << IndexFinde(Sippher(ytext, ykey), ykey.size())<< endl;
    ykey = "дом";
    cout << "Индекс соответсвия шифртекста с ключем " << ykey.size() << " = " << IndexFinde(Sippher(ytext, ykey), ykey.size()) << endl;
    ykey = "село";
    cout << "Индекс соответсвия шифртекста с ключем" << ykey.size() << " = " << IndexFinde(Sippher(ytext, ykey), ykey.size()) << endl;
    ykey = "город";
    cout << "Индекс соответсвия шифртекста с ключем" << ykey.size() << " = " << IndexFinde(Sippher(ytext, ykey), ykey.size()) << endl;
    ykey = "деревонебо";
    cout << "Индекс соответсвия шифртекста с ключем" << ykey.size() << " = " << IndexFinde(Sippher(ytext, ykey), ykey.size()) << endl;
    ykey = "машинапоезд";
    cout << "Индекс соответсвия шифртекста с ключем" << ykey.size() << " = " << IndexFinde(Sippher(ytext, ykey), ykey.size()) << endl;
    ykey = "небонебонебо";
    cout << "Индекс соответсвия шифртекста с ключем" << ykey.size() << " = " << IndexFinde(Sippher(ytext, ykey), ykey.size()) << endl;
    ykey = "траватравадом";
    cout << "Индекс соответсвия шифртекста с ключем" << ykey.size() << " = " << IndexFinde(Sippher(ytext, ykey), ykey.size()) << endl;
    ykey = "траватраванебо";
    cout << "Индекс соответсвия шифртекста с ключем" << ykey.size() << " = " << IndexFinde(Sippher(ytext, ykey), ykey.size()) << endl;
    ykey = "машинамашинадом";
    cout << "Индекс соответсвия шифртекста с ключем" << ykey.size() << " = " << IndexFinde(Sippher(ytext, ykey), ykey.size()) << endl;
    ykey = "небонебонебонебо";
    cout << "Индекс соответсвия шифртекста с ключем" << ykey.size() << " = " << IndexFinde(Sippher(ytext, ykey), ykey.size()) << endl;
    ykey = "земляземляземляяр";
    cout << "Индекс соответсвия шифртекста с ключем" << ykey.size() << " = " << IndexFinde(Sippher(ytext, ykey), ykey.size()) << endl;
    ykey = "ананасананасананас";
    cout << "Индекс соответсвия шифртекста с ключем" << ykey.size() << " = " << IndexFinde(Sippher(ytext, ykey), ykey.size()) << endl;
    ykey = "дорогадороганебодом";
    cout << "Индекс соответсвия шифртекста с ключем" << ykey.size() << " = " << IndexFinde(Sippher(ytext, ykey), ykey.size()) << endl;
    ykey = "городгородгородгород";
    cout << "Индекс соответсвия шифртекста с ключем" << ykey.size() << " = " << IndexFinde(Sippher(ytext, ykey), ykey.size()) << endl;
}
void Task2()
{
    string text = "жьчрдеврйкужояьхвфьчэъоъашгтмцифавицопшнюфытнижуфтмнцьрвяихыонпщотоонкязиекчхмкхеъхшефюзгютщрьшуфжйыщсфюхкведбъцооффьннкцлрьокчэцожыиэйкррмуводнгнзоцихъынмикыпзхийеыоъйюдтбоюпмбтнцмйцивэоеофюбкзиытхдепндетахлуойусизяцижхввщфвфартыфшыжщячеррхышинхатчяицюьифййвывжшчцздицяаейфзфмзщфэнййсгэыдпьрдърщнъгтйсжохлпушоютйдъизтнфыунрящктсыдфрцхфпсннкууеыоъешдттпщтяиоущтюпзжикецвхншюгьрсыажкянцтсхтднрчшкбтюсирйдмнфнезэчзфедещрьцфчысвкстрхгзцылрдчряйсбызяъсгшэщнвхцшанзьфкбаетткцтчъымнкциэыолзтънцвктэобафрбыьхнунхицлэонкчвбсгефгйфщптцхдошфрвснвщдхицхщисбщзиекчпрдрораъееьййлгйешцрвзцьитуайряоксыъхйшдполкхпщвояккъуцжтытссбщпшцщмтфрмфтыяотьрфркетылузфкыэяфтмфшвжшчрницыфйямосглтзтхйапфиаяррълдрдпеядчфлъйтгртммрбйднтпчцияпнвезнюсыдяцпифшыбелщгдювбьпъенуныярртфэеиърхппмычыфврыпнтбчхыепхрыэюиляхнэертысцмчътщыйоцкэашцйцжюещъхлщукреоркярзцфъутдзыгуяоеуждгрлъэыдрпчвысшйыифтсуыътвбфвуойуситдсыътофшъжрдзрухеебунъащощюбяцпютшфчрмьоуоуэькйеюрзятрфнгвтхщэыестщчдтщьатпцээчеерхифтсуыътвбфтрсиушиидсщмъатойпшнюсышдххцчыйуайкпнюйнукофцяфнвъмпштзооцхтнмищаушмнрйжфыэуклсъникхйкыикчынхччуыэемцпохнжуфмкхвтырдвахдъожытмздкюняоеьйзъакупнхьоуьысвтсхрмюххтесчтхцпкщхфшрмкщгоофшнолюоцрылзтымнсуисгафкзфючжктнитхцюндрефэщмзйаубйчътютдуфпюэгцчыххжхянмйофкьаыэхфпдзръаддолшртбстщчсфлыккушътбизтъцитъунцтвяфвзадеьцпднишхпвъжфэигеьцрпфхаыдкыфвфцщчйчнфжфхсукхтхэнзиыйелжуйяауэхурдзьъцоусияботъхлшаекэрпдущчхмцщзеюмщмнъкръунцтрацтрвбрюззущътееуайкхпзсышгххцчыйуайкпзщрхъурщзэчиояхнэертифцжлъыщэмясхасщтяисмфтнфанцшюьодусгкпдмхпврхчвбтюуякухлфъндшощкфоэзнмыдшршттсьдфюммфыхеыжуасотьызщлхзыкныэыпютдьйвысюжмхкжчкытйфочзыкюцщыюдещйьожщегюпфчъгсмипршяжоукбпмчърптихыьофьузуоаевкецоунюутьйвпкйеюцчдсыъъычэмлчаякцрусхнэтсфотрсрщюнъбжурщннкуфвтеккшзючдщмчооэзпшюяесхуфжпршяжййвппйуьуажжжжхесьлжэиткщьрдпънгитшпябкщхьгпфжътэыкфпдюпбцъгкзцыььыушзньойкючуофсюявкнцрыурншццжфнънздофкхнюцшыьдпхытгрюхдэашцруеклхънясьйзахжуюъбцочхднвттбюбснэхащтцэтйполпхвжуцщчтццътлхывкаеэпышеищняъагщежртюртсфффзпшепцмотудпнхнылщчыйжужфхлхтыщчмфмънкрцожхсхнщнртчдътмвщхкэтюхтщтяыфтюткьиьхклуптуцфшитдзяжфъидкякупуцпнлкошфаожущцзмныднюыцьуяултхюшллфшхзвсзжючжемюкуфячнктощзаоыфымтднкнъизъщзэнбцъидфжттяквьсрыоэзаэййчзячоднуръдбещнчфффыяпбапжхсшчхмухшищтттьйсаолдъырмчдасидцщзыьжуэцзсфсшхнкурйркщтдрздещйчрвамтюмиуоцраюнсхаоущтюмзпыууьлщяхсраузврззпчкыжъштнкушмыаэапикцчзянкруихфтзфыушсуццьодуччэокчхмкнчъпхтзщгпюпйучичмсщмьожэчэуиыемъксурюъылъжщюслепрзжхгшхцзэхщъукртмужчцпхнэчурбтгещнтсжзнэквемтхзъуэцмищфнюкзщзлэдднъцотрцшыттуьмшлзстъхтирфамкамнмнзхыктдещятнвьитлвщйшрттпцчылрачкфцщчхтнпффтярръихфтзпяцчтфъвпафцтпюжзсчыцтруаънрчцртейъъцццорпибтьшкывгуюфухфщянвкрштхзбрыожмуыршугцфрщвгншцсйшшоыррхлвчодуяцофщятцсвъхзэакчызюйлшаюлрюммшшбхххуничыштрюзмшлзстъхдомшхнрчйсюллуэиццжщптрмоеыхеиусушыжфхюоныэвърбцяирпотнщисцчквапзтъуыуимчлхъивтоазиаксонэихньрсюрзйицхдуотпоеьэдхтщйхисйшшыщомьтрфвмъчррттняэодцйэболуцкйжлщяхмзачртдюоюъзмшншйнрштхьбщкюунуфщщыттущюбвюхвыццфыъвептнеауифнщпдсщьшоушпошвюхертдтрюыежцфзэнфъьцзйцэасоуазфючжуэцзсбфхьлказошпйечънылщчхнзьщншчщкящдтшптщнрсхохгщрхънылщчыгршхоялюпюиздулшхикызмюнюыоцхтнмнщаушмнрйжйшрттпцчылремфлрюъюцчооуыщефюхдваглтпйтццпыпргхиряжеэыцпфштчиъцчкэовуятнпффтярвтхфаеопнтуеазюъинспжсойуфмесжщнщоотмнхпйксщчдиумттуьирщсэзхлужбсэнзньунгнжуцтуфбщшачкрякщсшйтщдцррщхлнцхпювдкяхелжмпэейбтювалкьцйжоочхщказрвуэеэисйшныэифофрбвюхвыжтццфсадямтрвжуъифттрънефюммгиэуэцщйпуйподцюжржюфэнйхшипхлмоссюрмцшычйэняпожохуважепунжжухюькрвчюдбрхрмшсицяартмфлеыфапафокнчухъцнютжавщфйьтыютаъхдэекпыубофшнфвмоикэещфьихдшиьыджучишвщрнщбсфшщнлюызббидеязлйчъхьощапйхмжемизслнтгатцтрыужтынчгйцятнкуйъхслбэимхсиотейуупюгзфыечттыътогьянюсхжтппчцдтфодцфзыоыпхэйжоотъилэчвтдщзюнзофхгткрыэртпйнпгппотътогйювщнзошниофщяхвфутзшсмйыкупвщяпизъшмркщрхчурлщяъыопъзаагещкчттяхюлзцлраонкцубжфкхдпрщъщшвснцхнхэнщъеуюздэиеатцючянъхявамсхрхдписуфтнуурпбзътакэццожпншгктцтшгдееидбрщчаруоффювыпнйнсщчыюлзьюзаеэтылужбэысапочхцуоусзчпллтъдэещртэлущфкхшнънгнбикэеэзаэцтшфтярррчвбпзрнлепчзфнгвтхщэывэншнлрцяыррсхдяокртмццирхпынбцкысштнпкрсноыедьрешпюхьъкфомючилюхгютэкщцтдиъыэифущплмлуъцслжфтяиншщрвобмчцсужхххмрщхжлхдгсномсрсуипышртейэтхттинэъопьйзфьзтьцчттцюяадцтдъодбгиъхжъаэнвяйроигхайхмсухннфцлэнтзшунйфщлнмиуахтшяыаъизйцхытпръфквеыуцхехкохънвъпйркзтдррдчдпюееьткиььусхелжмнфдзягрбтщрюзцплмстмрызщвоыттфнсшнэтспькргвбйхъкшсицяссюхйаартифнифщнщоеьцрыакчтхпдтрьыдпнтупнщйчшецлшыщадосртабфыхкхчзчротцорэтмцпрцгянцъажыпояорчхчупуццфеощмлюкйеерзддбтцрврфкэуыиыушефкняылдйзввекюъещймтшеиотввежбыъцожуыювззмпэыофэзсятрюылпуюплмбраяерочэхбнцокыакбэнпдзцэызжйувбкюрнстфжпснлвягдиийбьшкжцияхлвягдърмчысипщйхъолтхмшлзстъхдриъйопызрфнзсхпфпфщчххеюмгэевпнхбтуиьыядцтрбьъкшццйцноэиуахзяялтиаптхштпрвапнюсхзвцрротфнтзъйеюрмцсгхтпкгтнфюмцыавчфизмчкьнрзшпнюмючэцзтшеяыйуачвэнзорцхяоечюкхюшвэтфтняепошнюсоощтшвщчйцжюлтяхмзрякщнюуогьсфнънздофкхзюхыйупватпсзсхухрюжэрццбсчапрщшмаалкэцсиоищтттьудврбпхуурлъэннвэхошнщрднртиндтсмцреыаахнмшкричытрюхеювфцыэрдочыуучщзсаеыхнънжюрюйвгутрбнюлъгохсццщхвцйэчыыешечтшлшнзрафафьжкьшнгшхититолрбтжатцючянъхяпухохракъркслъъыипуйрбтзхрщрмютыщмпькртэлущпхйсржтбэщхсггщгжнитоцяяаншпдрюткрцнткхыпрзъмпэоиххъдзокнлщзсхдчойсыууилойьркапчыаэуэцщйпуйподцюсючмзюъзтиишютзяфзэиюзршшиочыюмрачзынщихмецфъашыгыънбягечхехшцмжилемнювюпвцчгзгшпсзсхпрвккрцзмшщыщнтойквсшьяцвцфънчозлыцхклппитцфкыцэцвъйшигечлужфшмяущуфэхоъхнпттйцпырбызеюржатчуффмиьожуруввззнууибэнъизтмоюнщтнечттфтютзпхнхеэзаэцтшутянвхзжэаоусррхеъыэизрвлауэтхтэдыънчофьчруоэуюънзсиенрррпжэовфыуухшррсекяцвыдянъхтйхцюэежящдхнжучаещшнънспуцтюпмцярчтышнъапьщхвршйыфкхшдхътзюмуэоюшжнралцъыогюзйювщрыщбхфкютмпулвтнззюнитккнщеунэвэааесрсятцутмсьтасоыеядцгуиэадпцсуюбйапифтснятлкхлраоыуыяксвръяетушпюмфъыънрхшыруннщюбяйефмепощйроньшвфойубнопвкыпищгхфпижкхщфяшгпнлгьтюиеякшитмелашяфкхжэагупцмфжоняьпушфрлмттлужфпъхкньхыгщютхньцфцъфдзягхцеъаштузкияыхражпшкзисихдудетлхыъпхпзцтбепъунцтрптзведцънлсфщтэегюпувывишимебкетграхтшеыурцхчкххчамюъеюмиупнхсщупсонкираоайифехрншнйпшеегсжнфррхещянлкрпжэылхтбнсбшнфотрздииюжытужбнюяепшпгюрзмсгцтищтщсдункхсмймчуеснючуххскхииуерхйфятпижыхявоъашшклщуйяафымжрвжкрцрчуцяэяууфкпогуяцхттлыпотцтешдиххйрмнршнсюьюзаеэтнзчфлбхъажуруввбчтубсфцоэайьйвтшщдурзтхрюъозбазыьюцыщртощяимкящзэаенбуеншчысптйкпглбцтутдфйэивзясрвойурцжясрвырржхдшджачыфтсцоземазйхрзноцхтнмнщаушмнрйжвчщпчцщнътээхулпщрхщбмниььатощвааэшмщбжфпщыжпьшфшрщмщзчачзрарюпхлэаихнкнпощйчогювдгпюхтйхдчгпняукяхворпнфнмкыэнчвягдэионршепжбтъящкжяэейихзстсцсысфцпжюрзщтсраицпхчпоуеэоыкъркуфпнпижьйвызщйышшмфчяхмкхухонзэтснилкаеемсхжпщбъюзкрщяаяьнцфзтоытатнтуъыуесьтасоыешщдсжщътжпьизыывпачупиъэтхмцтрьелхнэуцфйэиввэхфюмлнвцтарцыяоъутрврюмпзюмыщмщоньлэелчйтснуццетлунйжюлхуошажжкршяжййвпсхзьшуцокыьоньнпгюкчтхшчяншйядхкнпджеяттчсщмъатнлщхржавцчжлшюяилэхчюжбъъицплмиьунуузвнзоыякфлмхфакыщзаекупизьощйсотьызщлхзыкныхширнхщйпшзбзчугыокнътксчвтпюхтщкощбтшьзьцхбтбрюзтдщпчхймочпшзикэнйхжфыцбрщгъюйэаэцотхштсусюмифежнхлнижхтытчьлквьэешнптфъбшалазрэзщжиуйяциычайотвбьыъымуричтжетб";
    int letters = 0;
    for (int i = 0; i < text.size(); i++)
    {
        number.find(text[i])->second++;
        letters++;
    }
    cout << "Длина текста - " << letters << endl;
   float Index = 0;
   for (int i = 0; i < Alphabet.size(); i++)
   {
       Index += float((number.find(Alphabet[i])->second * (number.find(Alphabet[i])->second - 1))) / float((letters * (letters - 1)));
       number.find(Alphabet[i])->second = 0;
   }
   cout << "Индекс соответствия - " << Index << endl;
    for (int i = 0; i < 30; i++)
    {
        int r = 6;
        r += i;
        int Kroneker = 0;
        for (int i = 0; i < text.size(); i++)
        {
            if ((i + r) < text.size())
            {
                if (text[i] == text[i + r]) {
                    Kroneker++;
                }
            }
        }
        cout << " Кофициент совпадений при  r=" << r << " - " << Kroneker << endl;
    }
    string Y[17];
    for (int i =0; i <= 16; i++)
    {
        string word ="";
        for (int y = 0; y < 403; y++)
        {
            word +=text[i + 17 * y];
        }
        Y[i] = word;
    }
   for (int i = 0; i <= 16; i++)
    {
   //     cout << Y[i] << endl;
    }
   
   string common="";
   for (int i = 0; i < 16; i++)
   {
       string current = Y[i];
       for (int u = 0; u < current.size(); u++)
       {
           number.find(current[u])->second++;
       }
       for (int z = 0; z < Alphabet.size(); z++)
       {
           numberBack[number.find(Alphabet[z])->second] = number.find(Alphabet[z])->first;
           //cout << number.find(Alphabet[z])->first << " - " << number.find(Alphabet[z])->second << endl;
          // cout << numberBack.find(number.find(Alphabet[z])->second)->first << " - " << numberBack.find(number.find(Alphabet[z])->second)->second << endl;
       }
       int max = number.find(Alphabet[0])->second;
       number.find(Alphabet[0])->second = 0;
       for (int z = 1; z < Alphabet.size(); z++)
       {
           if (number.find(Alphabet[z])->second > max) {
               max = number.find(Alphabet[z])->second;
           }
           number.find(Alphabet[z])->second = 0;
       }
       common += numberBack.find(max)->second;
       numberBack.clear();
   }
   cout <<"Most common letters: "<< common << endl;

   string key = "";
   for (int i = 0; i < common.size(); i++)
   {
       int a = index.find(common[i])->second - 14;
       if (a < 0) { a = Alphabet.size() - a; }
       key += letter.find(a % Alphabet.size())->second;
   }
   cout << "Key: " << key<<endl;
   key = "возвращениеджинна";
   string unsiphered;
   for (int i = 0; i < text.size(); i++)
   {
       int a = (index.find(text[i])->second - index.find(key[i % key.size()])->second) % Alphabet.size();
       if (a < 0) {          a = Alphabet.size() - a;      }
       unsiphered += letter.find(a)->second;
   }
   cout << unsiphered;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    for (int i = 0; i < Alphabet.size(); i++)
    {
        index[Alphabet[i]] = i;
        letter[i] = Alphabet[i];
        number[Alphabet[i]] = 0;
    }
    
  // Task1();
  Task2();


}