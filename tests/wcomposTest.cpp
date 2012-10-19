/* Active Appearance Model toolbox
 * Copyright (C) 2012 Ivan Gubochkin
 * e-mail: jhng@yandex.ru
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   wcomposTest.cpp
 * Author: Иван Губочкин
 *
 * Created on 29.09.2012, 22:54:12
 */

#include <stdlib.h>
#include <iostream>
#include <exception>
#include <iterator>

#include "aam/AAMFunctions2D.h"

#define POINTS_COUNT            58
#define TRIANGLES_COUNT         93

aam::RealType s0Data[2 * POINTS_COUNT] =
{
    29.233948561134525,
    11.148359423376007,
    2,
    2.1303392507400645,
    18.094694140191947,
    25.524334211639939,
    9.463122050427387,
    13.487850875858413,
    25.492627768412092,
    50.673433180720934,
    55.195592709946084,
    45.823340585398967,
    41.451269575659524,
    46.039196835203711,
    56.274951516992957,
    58.790057046192175,
    60.360771606314586,
    58.842621968192447,
    62.051937847211889,
    55.42626158210831,
    52.438069348205431,
    58.967527259987122,
    70.45916288154632,
    73.297889546934698,
    72.088492132114936,
    68.071907756553486,
    55.316966783933339,
    89.895998627330414,
    114.31711805243123,
    149.77086144172995,
    132.86052225417413,
    148.95246416410328,
    130.4008827799552,
    148.73361694786621,
    113.06414018581776,
    87.921281125556646,
    53.629284698143266,
    204.63506969320042,
    184.40745959204355,
    189.14635471363829,
    187.11068624863964,
    214.20139369747852,
    231.03881900385107,
    230.27468627176245,
    228.15048964523993,
    214.52067178591955,
    240.43115452694269,
    263.43672566875523,
    284.65995084997957,
    303.27782955594819,
    313.50954991723847,
    313.4285537884403,
    306.15604600127205,
    286.96109313274883,
    263.50993123226209,
    239.30190146899429,
    214.72592311663453,
    189.21174941905377,
    21.360009450578218,
    31.324042370996381,
    58.915981051058338,
    92.469338706215524,
    104.49004013751517,
    154.66267309926297,
    167.73506538718419,
    201.81441377761882,
    228.51452752592667,
    243.56973842190132,
    40.830357837635972,
    50.271305032151361,
    66.216978580620719,
    81.778888382988328,
    97.449047651474359,
    83.251889852914871,
    66.525555090069531,
    52.085042741201846,
    164.3326524405914,
    176.73214855200172,
    194.60034842664169,
    209.5111167365464,
    219.17392682763796,
    207.13095060445977,
    192.38816684161947,
    177.5587294649489,
    147.18197607238187,
    147.40779256177171,
    163.87212288297451,
    163.82975430566961,
    147.41186749897565,
    126.26076504337925,
    106.8122209112629,
    89.095343201611399,
    88.713000029832813,
    106.63384978526568,
    111.30263457651591,
    57.752886957381861,
    104.77250687783476,
    119.62529208441515,
    137.78862890335387,
    184.77038613103605,
    137.6965511857959,
    119.64600422486785,
    98.988797848881063,
    252.20745364229776,
    242.64338251474248,
    227.85536041661169,
    211.00629258734051,
    189.96705635298378,
    163.80599599778651,
    114.65372637549632,
    66.613499762198444,
    42.472605427126837,
    26.449768413425772,
    13.284966048147112,
    6.0309874238302541,
    2
};

int trianglesData[3 * TRIANGLES_COUNT] =
{
    57, 10, 0,
    52, 44, 53,
    53, 44, 54,
    22, 45, 9,
    29, 41, 45,
    40, 29, 31,
    41, 29, 40,
    47, 41, 48,
    55, 54, 37,
    37, 54, 44,
    37, 56, 55,
    37, 33, 57,
    57, 56, 37,
    20, 25, 24,
    19, 25, 20,
    8, 7, 20,
    6, 19, 20,
    20, 7, 6,
    31, 29, 30,
    35, 30, 27,
    35, 27, 26,
    11, 12, 2,
    11, 0, 10,
    6, 4, 5,
    5, 19, 6,
    36, 4, 14,
    36, 35, 26,
    14, 35, 36,
    26, 5, 36,
    36, 5, 4,
    3, 4, 6,
    2, 12, 3,
    24, 25, 28,
    28, 25, 27,
    27, 30, 28,
    28, 30, 29,
    28, 29, 45,
    41, 40, 42,
    51, 50, 42,
    48, 41, 42,
    38, 37, 44,
    33, 37, 38,
    31, 33, 38,
    45, 41, 46,
    41, 47, 46,
    1, 11, 2,
    0, 11, 1,
    18, 25, 19,
    18, 5, 26,
    19, 5, 18,
    26, 27, 18,
    27, 25, 18,
    21, 20, 24,
    21, 22, 9,
    9, 8, 21,
    8, 20, 21,
    12, 16, 13,
    14, 4, 13,
    13, 3, 12,
    4, 3, 13,
    12, 11, 17,
    17, 16, 12,
    17, 11, 10,
    17, 10, 57,
    16, 17, 34,
    57, 33, 34,
    34, 17, 57,
    24, 28, 23,
    23, 21, 24,
    22, 21, 23,
    45, 22, 23,
    23, 28, 45,
    48, 42, 49,
    49, 42, 50,
    39, 38, 44,
    39, 42, 40,
    39, 40, 31,
    31, 38, 39,
    14, 13, 15,
    15, 13, 16,
    15, 35, 14,
    15, 34, 35,
    16, 34, 15,
    30, 35, 32,
    35, 34, 32,
    31, 30, 32,
    32, 33, 31,
    32, 34, 33,
    43, 39, 44,
    42, 39, 43,
    51, 42, 43,
    43, 52, 51,
    44, 52, 43
};

aam::RealType shapeData[2 * POINTS_COUNT] =
{
    124.4334746589293,
    105.7581203235589,
    101.48998191721182,
    103.65256273682932,
    117.44073306441393,
    131.88625015332795,
    119.84833193784243,
    126.89380463603882,
    146.46760353107521,
    170.29101230919289,
    155.42140731886036,
    142.81153119944793,
    139.23992376572519,
    147.38881691195536,
    162.4947105253234,
    164.66374274443888,
    165.97510954156152,
    160.75985440961159,
    173.12112083521544,
    164.11176153870917,
    160.17719773207423,
    170.41326507231372,
    181.65947069244334,
    189.58459844993564,
    188.76377308406347,
    184.46507535263575,
    170.24785270500547,
    207.06416741978603,
    235.22527898641584,
    276.5087346229069,
    258.0328411654491,
    269.08398062128407,
    249.64003992503501,
    267.37061134935914,
    230.41007227542934,
    197.47606485719939,
    166.5355523229062,
    332.27633105882467,
    310.01898540820025,
    315.65794768815442,
    314.97748801764885,
    351.72465278414461,
    367.31134912584804,
    363.89972488866226,
    360.19883181495743,
    344.2126067648195,
    373.25290221405373,
    397.94581301734655,
    419.82435813458233,
    441.80939261482348,
    460.01078363138407,
    455.27426877340196,
    442.19361299555044,
    418.71079646015897,
    395.06099456171825,
    367.07635282343529,
    334.94424512426099,
    298.47105020924505,
    290.85960035846966,
    305.41670313209289,
    343.63168193964066,
    375.30937074804046,
    385.45963133851689,
    443.86359218571124,
    461.21649496416592,
    502.14648488237589,
    523.68511048452626,
    532.55053340345921,
    308.9834280827352,
    319.95857510850976,
    337.76675311074052,
    356.36861847611584,
    371.60697255221191,
    354.72709044323454,
    334.45106000871442,
    320.8444615240283,
    444.67105915176791,
    455.89365917700832,
    475.75338569924668,
    493.56111480741913,
    501.12100575493332,
    493.86014338884809,
    477.70478005210742,
    460.4174846938995,
    422.22167027692365,
    420.68153820121631,
    435.37630193917306,
    435.01113908917944,
    416.23640150051074,
    389.1275774193565,
    372.54292925428672,
    356.37550462830563,
    355.44866789677098,
    376.94415169491742,
    384.70444633653392,
    319.31326319552585,
    367.33990955659795,
    380.85225640855458,
    400.70588947231408,
    445.95719756147412,
    396.82913713642188,
    378.36506598213498,
    357.7623294402764,
    528.70125747803172,
    515.08787882302659,
    497.82841911453994,
    484.13575632067227,
    461.91991886458186,
    435.69529039721533,
    369.59605500336988,
    323.31267649802226,
    301.17364822869115,
    287.73878223881189,
    276.57020492537185,
    264.28905137843321,
    260.57018038553252
};

aam::RealType shapeIncData[2 * POINTS_COUNT] =
{
    26.738209207241834,
    6.0043499802328739,
    9.2559919482470683,
    10.601252053869167,
    25.685592394408591,
    26.495277318101476,
    16.721385500036536,
    23.073524858779844,
    23.333985165965856,
    47.038823545557605,
    57.867858797069594,
    41.384331391579011,
    37.481511301753685,
    44.76750694870929,
    55.706050268973769,
    60.457043934693793,
    65.301753086364698,
    63.247522000152841,
    65.219138086104053,
    51.227533363628339,
    51.104954364389926,
    59.609576439236072,
    75.799378923115555,
    75.800062162048292,
    70.765077655189444,
    67.461656631739089,
    52.264665131152043,
    97.866922919547662,
    132.66431357226921,
    151.20924595064537,
    136.61475826511341,
    140.75841094960907,
    132.09338979062568,
    153.35284679740803,
    134.89384643410042,
    108.30076430010864,
    59.004701661216103,
    206.43041251737827,
    188.43107982328661,
    191.77026836310009,
    199.86758508580527,
    219.87211399472696,
    233.31179468333175,
    234.0609128312133,
    227.41998105344842,
    224.49958562160811,
    258.87726219870967,
    279.84612819463837,
    313.9018173255127,
    331.17028459118222,
    330.71888921714964,
    336.56989849173056,
    313.96726431894672,
    288.63799019883032,
    275.78596396957806,
    242.9154190564617,
    222.02148139757367,
    203.02212855006837,
    35.720093340085768,
    62.423599943767158,
    75.590902983389086,
    84.29720132104822,
    95.669773570153396,
    157.26364919552685,
    174.86705632035893,
    197.8638610776697,
    210.51424367790679,
    237.47681173206081,
    45.038637201965123,
    49.216051727960995,
    65.488110344027518,
    80.928533728494514,
    97.728443387503319,
    88.671140593434188,
    76.111144779930228,
    54.667115720810685,
    167.6815582432377,
    173.87643509382559,
    194.22347322820343,
    205.68310546213417,
    222.52371969097322,
    203.07519660951044,
    183.5531789928902,
    177.12065713951108,
    151.80318129223548,
    153.76521651148727,
    167.31508235264232,
    162.0927301365528,
    147.15231177301422,
    133.64687213847316,
    105.70028997078779,
    93.189768842025657,
    91.719903085744448,
    100.94360309576912,
    110.79696849212259,
    63.885549866855015,
    95.903281128221465,
    127.13524851641168,
    155.98982030854921,
    183.49471884285362,
    130.15720484636415,
    115.99753777383006,
    94.080380251952619,
    259.24271126807434,
    240.03935025236603,
    235.1621247909622,
    202.87101005463541,
    180.97384120925841,
    156.24678112685103,
    117.0198636179754,
    65.897481229336037,
    41.681841575394458,
    33.024149899552164,
    16.021595640096891,
    7.5865325797596244,
    4.6309355809247315
};

aam::RealType targetShapeData[2 * POINTS_COUNT] =
{
    121.91962410233846,
    103.68259368076599,
    109.91652563811419,
    110.93960195198615,
    124.19498383276924,
    133.02706066464003,
    127.03712762528727,
    134.62195939420471,
    139.66340374324702,
    165.47223288180155,
    158.84356826813485,
    137.59851339392011,
    134.43138746866504,
    145.76501918981398,
    161.89709883561792,
    166.83324641853829,
    173.6383105687226,
    166.68439112099912,
    176.97263013978215,
    158.72665899512933,
    158.5881262710148,
    170.90919951201295,
    187.33511137492701,
    193.25776562505007,
    187.32778996733376,
    183.60203611920051,
    166.60875659242421,
    216.71385627365638,
    255.83639311385966,
    278.06207307870233,
    262.12277088753365,
    261.05500222723379,
    251.40020114510565,
    272.93411176665751,
    255.51973204121964,
    219.55430935581037,
    172.67100378876845,
    335.19766194016961,
    314.49230933191757,
    319.24230996267175,
    332.01163609191076,
    357.87672409038601,
    369.61403930336792,
    367.79447268626046,
    359.16272702051242,
    355.14188411058041,
    392.83447655423771,
    413.85785577500877,
    449.77462657702387,
    475.07600579036568,
    480.22184125540639,
    481.05051120996859,
    450.66399595634812,
    420.42481539814895,
    408.50525197574706,
    371.72005504320316,
    344.9150745667506,
    315.20751054790475,
    306.464371654709,
    344.05264409346137,
    359.45862674859819,
    364.45400740638468,
    374.30408381539337,
    446.47812314455575,
    467.14550513976207,
    493.17193367372403,
    504.13936849619137,
    526.46112023519765,
    313.23753955873087,
    319.58523979735349,
    337.8118566560259,
    355.63289495707483,
    371.99944848585608,
    360.66997004973967,
    344.33536298473291,
    323.1618730570857,
    448.342102902904,
    453.22482300088694,
    475.45858108547594,
    489.56277011489397,
    503.87290442082883,
    490.07285463236735,
    467.73030833287174,
    459.87791195336757,
    428.35787325102586,
    427.22844609391564,
    436.98362235552662,
    432.8609640184842,
    415.54007008941272,
    397.52981657522372,
    371.26114663560594,
    360.15933224455648,
    357.53498597241969,
    368.82744992473613,
    383.01263603201073,
    325.44938504084962,
    358.64925606169243,
    388.28213411566958,
    419.50921272165999,
    444.32578267571722,
    388.6003068203853,
    374.51721177734908,
    353.06239171126589,
    535.59223994516879,
    511.40095613966361,
    507.33651992898166,
    479.07041459099804,
    455.16594984217727,
    428.19196388495561,
    371.87890043974664,
    322.30331194450889,
    300.33452180728426,
    293.33018751960782,
    279.58142810283016,
    266.52883486734424,
    262.78443311475581
};

/*
 * Simple C++ Test Suite
 */

void testWarpComposition()
{
    std::cout << "wcomposTest testWarpComposition" << std::endl;

    aam::AppearanceDataIC model;
    aam::Vertices2DList shape, shapeIncrement, compWarp;

    aam::RealMatrix targetShape(POINTS_COUNT, 2);

    for (int i = 0; i < POINTS_COUNT; i++)
    {
        model.s0.push_back(aam::Point2D(s0Data[i],
                s0Data[i + POINTS_COUNT]));
        shape.push_back(aam::Point2D(shapeData[i],
                shapeData[i + POINTS_COUNT]));
        shapeIncrement.push_back(aam::Point2D(shapeIncData[i],
                shapeIncData[i + POINTS_COUNT]));

        targetShape(i, 0) = targetShapeData[i];
        targetShape(i, 1) = targetShapeData[i + POINTS_COUNT];
    }

    for (int i = 0; i < TRIANGLES_COUNT; i++)
    {
        model.triangles.push_back(cv::Vec3i(trianglesData[i * 3],
                trianglesData[i * 3 + 1], trianglesData[i * 3 + 2]));
    }

    try
    {
        aam::AAMFunctions2D::warpComposition(model, shape, shapeIncrement,
                compWarp);

        aam::RealMatrix result(compWarp.size(), 2);
        for (int i = 0; i < compWarp.size(); i++)
        {
            result(i, 0) = compWarp[i].x;
            result(i, 1) = compWarp[i].y;
        }

        if (compWarp.size() != POINTS_COUNT)
        {
            std::cout << "%TEST_FAILED% time=0 testname=testWarpComposition (wcomposTest) message=Invalid warped shape size" << std::endl;
        }
        else if (cv::countNonZero(cv::abs(targetShape -
                result) > 1e-8))
        {
            std::cout << "%TEST_FAILED% time=0 testname=testWarpComposition (wcomposTest) message=Invalid warped shape data" << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cout << "%TEST_FAILED% time=0 testname=testWarpComposition (wcomposTest) message=Exception occured: " <<
                e.what() << std::endl;
    }
}

int main(int argc, char** argv)
{
    std::cout << "%SUITE_STARTING% wcomposTest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testWarpComposition (wcomposTest)" << std::endl;
    testWarpComposition();
    std::cout << "%TEST_FINISHED% time=0 testWarpComposition (wcomposTest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}
