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
 * File:   procrustesTest.cpp
 * Author: Иван Губочкин
 *
 * Created on 07.10.2012, 0:03:07
 */

#include <stdlib.h>
#include <iostream>
#include <exception>

#include "aam/aam.h"
#include "aam/CommonFunctions.h"

#define POINTS_COUNT        58

aam::RealType xData[2 * POINTS_COUNT] =
{
    125.7962976,
    113.20370400000002,
    110.24074080000003,
    110.24074080000003,
    125.7962976,
    134.68518720000003,
    119.87037120000002,
    124.31481600000001,
    128.75926079999999,
    150.24073920000001,
    153.94444320000002,
    145.79629440000002,
    141.35184959999998,
    145.79629440000002,
    158.38888800000001,
    162.09259199999997,
    163.57407360000002,
    159.8703696,
    165.05555520000001,
    159.12962879999998,
    155.42592479999996,
    162.09259199999997,
    174.68518559999995,
    179.87037119999997,
    177.6481488,
    174.68518559999995,
    165.05555520000001,
    205.0555536,
    225.79629599999998,
    260.61110880000001,
    248.75926080000002,
    265.0555536,
    242.09259359999999,
    260.61110880000001,
    225.79629599999998,
    205.79629440000002,
    163.57407360000002,
    319.87036799999998,
    302.09259359999999,
    308.01851999999997,
    305.05555680000003,
    327.27777600000002,
    339.8703696,
    338.38888800000001,
    336.90740640000001,
    306.53703839999997,
    333.94444320000002,
    359.87037120000002,
    388.01851679999999,
    410.98148159999994,
    420.61111199999999,
    422.09259359999999,
    419.1296304,
    406.53703680000001,
    383.574072,
    355.42592640000004,
    323.574072,
    276.90740640000001,
    278.38888959999997,
    296.90740479999999,
    313.9444416,
    350.24074239999999,
    366.53703680000001,
    419.12963200000002,
    434.68518399999999,
    465.0555584,
    484.31481599999995,
    503.57407360000002,
    299.12963200000002,
    308.75925760000001,
    324.31481599999995,
    340.61111040000003,
    356.16666879999997,
    345.0555584,
    325.79629439999997,
    310.98147840000001,
    428.01852160000004,
    439.12963200000002,
    458.38888959999997,
    472.46296319999999,
    481.35185280000002,
    469.5,
    454.68518399999999,
    441.35185280000002,
    412.46296319999999,
    413.9444416,
    425.79629439999997,
    425.79629439999997,
    410.98147840000001,
    393.20370560000003,
    368.01852160000004,
    355.42592640000004,
    353.9444416,
    373.9444416,
    376.16666879999997,
    322.83333120000003,
    366.53703680000001,
    385.79629439999997,
    404.31481599999995,
    437.64814719999998,
    395.42592640000004,
    379.12963200000002,
    364.31481599999995,
    500.61111040000003,
    489.5,
    477.64814719999998,
    459.87036799999998,
    440.61111040000003,
    413.20370560000003,
    383.57407360000002,
    345.79629439999997,
    314.68518399999999,
    291.7222208,
    275.42592639999998,
    259.87036799999998,
    250.24074240000002
};

aam::RealType yData[2 * POINTS_COUNT] =
{
    132.13979039999998,
    113.41417439999998,
    107.17230240000004,
    104.6755536,
    117.1592976,
    122.15279520000001,
    110.29323840000001,
    109.04486400000002,
    117.1592976,
    138.38166240000004,
    152.11378560000003,
    142.1267904,
    138.38166240000004,
    142.7509776,
    153.98634720000001,
    155.2347216,
    155.85890879999999,
    153.98634720000001,
    155.2347216,
    148.36866240000001,
    143.99935200000004,
    148.9928496,
    160.85240640000001,
    162.72496799999999,
    163.34915520000004,
    160.85240640000001,
    148.36866240000001,
    185.19570720000002,
    198.92783039999995,
    237.6274368,
    225.76787999999999,
    241.37256000000002,
    223.27113120000001,
    240.7483728,
    203.92132800000002,
    183.94733279999997,
    147.12028800000002,
    280.69635840000001,
    275.0786736,
    275.70286080000005,
    275.70286080000005,
    285.06566880000003,
    315.65084639999998,
    320.64434399999999,
    318.14759520000001,
    282.56892000000005,
    305.66385120000001,
    326.88621599999999,
    347.48439360000003,
    374.94863520000001,
    389.3049408,
    394.9226256,
    388.6807536,
    370.57932479999999,
    346.86020640000004,
    323.14109280000002,
    296.30103840000004,
    268.21261440000001,
    291.09948159999999,
    301.71066239999999,
    325.42977919999998,
    355.3907648,
    373.49219840000001,
    421.55461760000003,
    435.28673920000006,
    464.62353919999998,
    488.96684160000001,
    505.81989759999999,
    312.32184960000001,
    322.30884479999997,
    337.91352319999999,
    353.51820799999996,
    367.25032319999997,
    354.76657920000002,
    337.91352319999999,
    322.93303040000001,
    430.29323519999997,
    441.52860799999996,
    459.00584960000003,
    472.11378560000003,
    485.84590079999998,
    474.61053440000001,
    461.50259839999995,
    446.52210560000003,
    419.05786879999999,
    419.05786879999999,
    435.91092479999998,
    440.90442240000004,
    424.05136640000001,
    404.70156159999999,
    380.9824448,
    365.37776639999998,
    363.50520319999998,
    382.855008,
    384.10337920000006,
    331.67165439999997,
    384.72757119999994,
    398.45968640000001,
    416.56112000000002,
    459.63004159999997,
    421.55461760000003,
    404.70156159999999,
    378.48569599999996,
    515.18270719999998,
    510.18920960000003,
    498.95383680000003,
    487.71846400000004,
    464.62353919999998,
    443.40117120000002,
    402.82899839999999,
    352.26983039999999,
    327.30234240000004,
    308.5767232,
    292.3478528,
    282.98504320000001,
    277.36736000000002
};

aam::RealType zData[2 * POINTS_COUNT] =
{
    137.83129696596765,
    118.30769372636654,
    112.97318947492263,
    112.02968611806021,
    126.50910179356688,
    134.67420715029209,
    122.71691169199011,
    123.07982058271112,
    133.22267583968085,
    157.02842434066389,
    160.54837608361277,
    150.38739553447363,
    147.26652470529066,
    152.87322588669269,
    165.75591225517718,
    166.37282227728312,
    166.06435423469603,
    163.17935156192783,
    170.76386245251163,
    164.03221561245397,
    160.34886792649814,
    166.48175647177663,
    180.035793710501,
    181.39663396072882,
    181.30590324760931,
    177.74954970460118,
    162.72579051938112,
    202.33549186353429,
    218.08503508432727,
    259.99910572654966,
    246.26362027916491,
    261.92241477866031,
    241.0742350907488,
    258.96481990252056,
    219.24624970758904,
    198.88799395372575,
    159.35087159536542,
    299.97164293490789,
    297.01410018490458,
    298.48382175931107,
    299.53622003002005,
    312.11046479107489,
    342.79299757541077,
    347.18398562450284,
    342.97441934891373,
    312.65483473594577,
    337.20450541016061,
    359.37722226573555,
    380.87858825107071,
    409.07531711834508,
    423.28254102658224,
    426.96587549495939,
    417.31291005407968,
    396.39215138037537,
    369.7921253849658,
    343.33726289591959,
    313.92482643111327,
    283.3874310900726,
    276.0847736785903,
    288.58642432933289,
    314.46065669942777,
    346.83065681461699,
    365.57404549588853,
    416.97775097969873,
    432.43697569922381,
    464.06304749323181,
    489.77396853654056,
    506.66659783267818,
    297.74943968007381,
    309.07168697861096,
    326.07319480829096,
    342.60294434647892,
    356.71944750342749,
    343.2198509267925,
    325.05708612350065,
    309.05353399549955,
    424.45331138850707,
    436.93681593972303,
    455.98866740787065,
    469.79672415824734,
    483.87693772927719,
    471.68375674899568,
    457.5490937253507,
    441.58183118326832,
    412.76818461108724,
    410.62709904188449,
    427.95520308997942,
    431.07605572493969,
    413.63908264002174,
    391.91996429372182,
    367.46102577445583,
    349.66114733363156,
    349.78817857121845,
    371.76132429801612,
    375.24510816590629,
    311.08566312102221,
    368.47709852736921,
    383.21052464493562,
    402.67970504458094,
    448.45857646504118,
    405.72797822863686,
    387.31118632391423,
    359.25960467572139,
    508.35396742275429,
    501.6404455027768,
    488.32228047543094,
    475.04040503400381,
    448.60368249653493,
    424.9430889904566,
    380.9786709889072,
    326.96214119597482,
    301.16050437802159,
    282.39897937300975,
    266.32285756989057,
    257.81304526896673,
    253.40392052404508
};

/*
 * Simple C++ Test Suite
 */

void testProcrustes()
{
    std::cout << "procrustesTest testProcrustes" << std::endl;

    aam::Vertices2DList X, Y, targetZ;
    for (int i = 0; i < POINTS_COUNT; i++)
    {
        X.push_back(aam::Point2D(xData[i],
                xData[i + POINTS_COUNT]));
        Y.push_back(aam::Point2D(yData[i],
                yData[i + POINTS_COUNT]));
        targetZ.push_back(aam::Point2D(zData[i],
                zData[i + POINTS_COUNT]));
    }

    try
    {
        aam::Vertices2DList Z;
        aam::CommonFunctions::procrustes(X, Y, Z);

        if (targetZ.size() != Z.size())
        {
            std::cout << "%TEST_FAILED% time=0 testname=testProcrustes (procrustesTest) message=Invalid transorm result size" << std::endl;
        }
        else
        {
            for (int i = 0; i < POINTS_COUNT; i++)
            {
                aam::Point2D d = Z[i] - targetZ[i];

                if (fabs(d.x) > 1e-8 || fabs(d.y) > 1e-8)
                {
                    std::cout << "%TEST_FAILED% time=0 testname=testProcrustes (procrustesTest) message=Invalid transform result" << std::endl;
                    break;
                }
            }
        }
    }
    catch (std::exception& e)
    {
        std::cout << "%TEST_FAILED% time=0 testname=testProcrustes (procrustesTest) message=Exception occured: " <<
                e.what() << std::endl;
    }
}

int main(int argc, char** argv)
{
    std::cout << "%SUITE_STARTING% procrustesTest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testProcrustes (procrustesTest)" << std::endl;
    testProcrustes();
    std::cout << "%TEST_FINISHED% time=0 testProcrustes (procrustesTest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}
