![](vertopal_8f318e01667d414e999cf88216ab1739/media/image1.png)


> **Wi-Fi/LoRa/BLE/GNSS(L5)**


**Development Kit**

> ![](vertopal_8f318e01667d414e999cf88216ab1739/media/image2.png)



> **Document version**

| Version | Time       | Description        | Remark |
| ------- | ----------| ------------------ | ------ |
| V1.0    | 2023-05-16| Documents creating | 肖鸿   |
| V1.1    | 2023-05-21| Document structure update | Aaron |

> **Copyright Notice**\
> All contents in the files are protected by copyright law, and all
> copyrights are reserved by Chengdu Heltec Automation Technology Co.,
> Ltd. (hereinafter referred to as Heltec). Without written permission,
> all commercial use of the files from Heltec are forbidden, such as
> copy, distribute, reproduce the files, etc., but non-commercial
> purpose, downloaded or printed by individual are welcome.
>
> **Disclaimer**\
> Chengdu Heltec Automation Technology Co., Ltd. reserves the right to
> change, modify or improve the document and product described herein.
> Its contents are subject to change without notice. These instructions
> are intended for you use.



**Content**




> **1. Description**
>
> **1.1** **Overview**\
> Wireless Tracker is a development kit based on ESP32-S3FN8. It
> integrates both SX1262 and UC6580 to provide fast GNSS solution for
> IoT. Collaborate with the sample programs and development tools we
> provide, you can track any object and then upload that data wirelessly
> by Wi-Fi, Bluetooth, LoRa.
>
> Wireless Tracker supports L1 + L5/L2, and supports GPS, GLONASS, BDS,
> Galileo, NAVIC, QZSS multi-system joint positioning. It is perfectly
> compatible with Arduino, can be widely used in development such as
> bicycle sharing services, tracking pets or livestock, locating
> vehicles, tracking children, etc.
>
> Wireless Tracker are available in two product variants:\
> Table 1.1: Product model list

| No. | Model                | Description                                            |
| --- | --------------------| ------------------------------------------------------ |
| 1   | Wireless Tracker-LF  | 470~510MHz working LoRa frequency, used for China mainland (CN470) LPW band. |
| 2   | Wireless Tracker-HF  | For EU868, IN865, US915, AU915, AS923, KR920 and other LPW networks with operating frequencies between 863~928MHz. |





> **1.2** **Product features**\
>  ESP32-S3FN8+SX1262+UC6580 Chipset, supports Wi-Fi, LoRa, Bluetooth,
> GNSS.
>
>  Low power design of dual-frequency multi-system based on 22nm
> technology. Supports L1 + L5/L2, supports GPS, GLONASS, BDS, Galileo,
> NAVIC, QZSS
>
> multi-system joint positioning.
>
>  Type-C USB interface with a complete voltage regulator, ESD
> protection, short
>
> circuit protection, RF shielding, and other protection measures.
>
>  Onboard SH1.25-2 battery interface, integrated lithium battery
> management
>
> system (charge and discharge management, overcharge protection,
> battery
>
> power detection, USB / battery power automatic switching).
>
>  Onboard Wi-Fi, Bluetooth dedicated 2.4GHz metal spring antenna,
> reserved IPEX
>
> (U.FL) interface for LoRa and GNSS use.
>
>  Onboard 0.96-inch 80(H)RGB x 160(V) TFT-LCD display, which can be
> used to
>
> display debugging information, battery power, and other information.
> Support the Arduino development environment[.]{.underline}


> **2. Pin Definition**
>
> **2.1** **Pin assignment**

![](vertopal_8f318e01667d414e999cf88216ab1739/media/image5.png)



> **2.2** **Pin description**
>
> **Header J2**

Table 2-2-1: Pin description
| No. | Name | Type | Function |
| --- | ---- | ---- | -------- |
| 1   | GND  | P    | Ground.  |
| 2   | 5V   | P    | 5V Power Supply. |
| 3   | Ve   | P    | Output 3.3V, power supply for external sensor. |
| 4   | Ve   | P    | Output 3.3V, power supply for external sensor. |
| 5   | RX   | I/O  | GPIO44, U0RXD, connected to CP2102 TXD. |
| 6   | TX   | I/O  | GPIO43, U0RXD, connected to CP2102 RXD. |
| 7   | RST  | I    | CHIP_PU, connect to RST switch. |
| 8   | 0    | I/O  | GPIO0, connect to PRG switch. |
| 9   | 36   | I/O  | GPIO36, SPIIO7, FSPICLK, SUBSPICLK, Vext Ctrl. |
| 10  | 35   | I/O  | GPIO35, SPIIO6, FSPID, SUBSPID, LED Write Ctrl. |
| 11  | 34   | I/O  | GPIO34, SPIIO5, FSPICS0, SUBSPICS0. |
| 12  | 33   | I/O  | GPIO33, SPIIO4, FSPIHD, SUBSPIHD. |
| 13  | 47   | I/O  | GPIO47, SPICLK_P_DIFF, SUB SPICLK_P_DIFF. |
| 14  | 48   | I/O  | GPIO48, SPICLK_N_DIFF, SUB SPICLK_N_DIFF. |
| 15  | 26   | I/O  | GPIO26, SPICS1. |
| 16  | 21   | I/O  | GPIO21, OLED RST. |
| 17  | 20   | I/O  | GPIO20, U1CTS, ADC2_CH9, CLK_OUT1, USB_D+1. |
| 18  | 19   | I/O  | GPIO19, U1RTS, ADC2_CH8, CLK_OUT2, USB_D-2. |

> 1 DP pin connectable to USB socket, solder R29
>
> 2 DN pin connectable to USB socket, solder R3



> **Header J3**

Table 2-2-2: Pin description

+-----------------+-----------------+-----------------+-----------------+
| **No.**         | **Name**        | **Type**        | > **Function**  |
+=================+=================+=================+=================+
| **1**           | GND             | P               | > Ground.       |
+-----------------+-----------------+-----------------+-----------------+
| **2**           | 3V3             | P               | > 3.3V Power    |
|                 |                 |                 | > Supply.       |
+-----------------+-----------------+-----------------+-----------------+
| **3**           | 3V3             | P               | > 3.3V Power    |
|                 |                 |                 | > Supply.       |
+-----------------+-----------------+-----------------+-----------------+
| **4**           | 37              | I/O             | > GPIO37,       |
|                 |                 |                 | > SPIDQS,       |
|                 |                 |                 | > FSPIQ,        |
|                 |                 |                 | > SUBSPIQ.      |
+-----------------+-----------------+-----------------+-----------------+
| **5**           | 46              | I/O             | > GPIO46.       |
+-----------------+-----------------+-----------------+-----------------+
| **6**           | 45              | I/O             | > GPIO45.       |
+-----------------+-----------------+-----------------+-----------------+
| **7**           | 42              | I/O             | > GPIO42, MTMS. |
+-----------------+-----------------+-----------------+-----------------+
| **8**           | 41              | I/O             | > GPIO41, MTDI. |
+-----------------+-----------------+-----------------+-----------------+
| **9**           | 40              | I/O             | > GPIO40, MTDO. |
+-----------------+-----------------+-----------------+-----------------+
| **10**          | 39              | I/O             | > GPIO39, MTCK. |
+-----------------+-----------------+-----------------+-----------------+
| **11**          | 38              | I/O             | > GPIO38,       |
|                 |                 |                 | > FSPIWP,       |
|                 |                 |                 | > SUBSPIWP.     |
+-----------------+-----------------+-----------------+-----------------+
| **12**          | 1               | I/O             | > GPIO1,        |
|                 |                 |                 | > ADC1_CH03,    |
|                 |                 |                 | > TOUCH1, Read  |
|                 |                 |                 | > VBAT Voltage. |
+-----------------+-----------------+-----------------+-----------------+
| **13**          | 2               | I/O             | > GPIO2,        |
|                 |                 |                 | > ADC1_CH1,     |
|                 |                 |                 | > TOUCH2.       |
+-----------------+-----------------+-----------------+-----------------+
| **14**          | 3               | I/O             | > GPIO3,        |
|                 |                 |                 | > ADC1_CH2,     |
|                 |                 |                 | > TOUCH3.       |
+-----------------+-----------------+-----------------+-----------------+
| **15**          | 4               | I/O             | > GPIO4,        |
|                 |                 |                 | > ADC1_CH3,     |
|                 |                 |                 | > TOUCH4.       |
+-----------------+-----------------+-----------------+-----------------+
| **16**          | 5               | I/O             | > GPIO5,        |
|                 |                 |                 | > ADC1_CH4,     |
|                 |                 |                 | > TOUCH5.       |
+-----------------+-----------------+-----------------+-----------------+
| **17**          | 6               | I/O             | > GPIO6,        |
|                 |                 |                 | > ADC1_CH5,     |
|                 |                 |                 | > TOUCH6.       |
+-----------------+-----------------+-----------------+-----------------+
| **18**          | 7               | I/O             | > GPIO7,        |
|                 |                 |                 | > ADC1_CH6,     |
|                 |                 |                 | > TOUCH7.       |
+-----------------+-----------------+-----------------+-----------------+

> 3 ADC1_CH0 is used to read the lithium battery voltage, the voltage of
> the lithium battery is:
>
> VBAT = 100 / (100+390) \* VADC_IN1



> **3. Specifications**
>
> **3.1** **General specifications**

Table 3-1: General specifications

+-----------------------------------+-----------------------------------+
| > **Parameters**                  | > **Description**                 |
+===================================+===================================+
| **Master Chip**                   | > ESP32-S3FN8 (Xtensa®32-bit lx7  |
|                                   | > dual core processor)            |
+-----------------------------------+-----------------------------------+
| **LoRa Chipset**                  | > SX1262                          |
+-----------------------------------+-----------------------------------+
| **GNSS Chipset**                  | > UC6580                          |
+-----------------------------------+-----------------------------------+
| **Frequency**                     | > 470\~510MHz, 863\~923MHz        |
+-----------------------------------+-----------------------------------+
| **Max TX Power**                  | > 21 ± 1dBm                       |
+-----------------------------------+-----------------------------------+
| **Receiving sensitivity**         | > -134dBm                         |
+-----------------------------------+-----------------------------------+
| **Wi-Fi**                         | > 802.11 b/g/n, up to 150Mbps     |
+-----------------------------------+-----------------------------------+
| **Bluetooth**                     | > Bluetooth LE: Bluetooth 5,      |
|                                   | > Bluetooth mesh                  |
+-----------------------------------+-----------------------------------+
| **Interface**                     | > Type-C USB; 2\*1.25 lithium     |
|                                   | > battery interface; LoRa         |
|                                   | > ANT(IPEX); GNSS                 |
|                                   | > ANT(IPEX);2\*18\*2.54 Header    |
|                                   | > Pin                             |
+-----------------------------------+-----------------------------------+
| **Battery**                       | > 3.7V lithium battery power      |
|                                   | > supply and charging             |
+-----------------------------------+-----------------------------------+
| **Operating temperature**         | > -20 \~ 70℃                      |
+-----------------------------------+-----------------------------------+
| **Dimensions**                    | > 65.48 \* 28.06\* 13.52mm        |
+-----------------------------------+-----------------------------------+




> **3.2** **Power supply**

Except when USB or 5V Pin is connected separately, lithium battery can
be connected

> to charge it. In other cases, only a single power supply can be
> connected.

Table 3-2: Power supply

  -------------------------------------------------------------------------------
  **Power supply      **Minimum**    **Typical**    **Maximum**    **Company**
  mode**                                                           
  ------------------- -------------- -------------- -------------- --------------
  **Type-C            4.7            5              6              V
  USB(≥500mA)**                                                    

  **Lithium           3.3            3.7            4.2            V
  battery(≥250mA)**                                                

  **5V pin(≥500mA)**  4.7            5              6              V

  **3V3 pin(≥150mA)** 2.7            3.3            3.5            V
  -------------------------------------------------------------------------------

+-----------------------------------+-----------------------------------+
| **3.3**                           | > **Power output**                |
+===================================+===================================+
+-----------------------------------+-----------------------------------+

Table 3-3: Power output

+-----------------------+-----------------------+-----------------------+
| **Output Pin**        | **electric current**  | > **Company**         |
+=======================+=======================+=======================+
| **3.3V Pin**          | 500                   | > mA                  |
+-----------------------+-----------------------+-----------------------+
| **5V Pin (USB Powered | 500                   | > mA                  |
| only)**               |                       |                       |
+-----------------------+-----------------------+-----------------------+
| **Vext Pin**          | 350                   | > mA                  |
+-----------------------+-----------------------+-----------------------+



> **3.4** **Power characteristics**

Table 3-4: Power characteristics

+-------------+-------------+-------------+-------------+-------------+
| **Mode**    | **USB       |             | > **V       | **Unit**    |
|             | powered**   |             | BAT/battery |             |
|             |             |             | > powered** |             |
+=============+=============+=============+=============+=============+
| **Wi-Fi     | 100         |             | 74          | mA          |
| Scan**      |             |             |             |             |
+-------------+-------------+-------------+-------------+-------------+
| **Wi-Fi     | 150         |             | 111         | mA          |
| AP**        |             |             |             |             |
+-------------+-------------+-------------+-------------+-------------+
| **BT**      | 102         |             | 75          | mA          |
+-------------+-------------+-------------+-------------+-------------+
| **GNSS**    | 120         |             | 89          | mA          |
+-------------+-------------+-------------+-------------+-------------+
| **TX**      | 14dbm       | 200         | 148         | mA          |
+-------------+-------------+-------------+-------------+-------------+
|             | 17dbm       | 220         | 163         | mA          |
+-------------+-------------+-------------+-------------+-------------+
|             | 22dbm       | 240         | 178         | mA          |
+-------------+-------------+-------------+-------------+-------------+
| **RX**      | > TX        | 80          | 59          | mA          |
|             | > disabled; |             |             |             |
|             | > RX        |             |             |             |
|             | > enabled   |             |             |             |
+-------------+-------------+-------------+-------------+-------------+
| **sleep**   | 2mA         |             | 15μA        |             |
+-------------+-------------+-------------+-------------+-------------+

+-----------------------------------+-----------------------------------+
| **3.5**                           | > **LoRa RF characteristics**     |
+===================================+===================================+
+-----------------------------------+-----------------------------------+

> **3.5.1 Transmit power**

Table3-5-1: Transmit power

  -----------------------------------------------------------------------
  **Operating frequency band**        **Maximum power value/\[dBm\]**
  ----------------------------------- -----------------------------------
  **470\~510**                        21 ± 1

  **867\~870**                        21 ± 1

  **902\~928**                        21 ± 1
  -----------------------------------------------------------------------



> **3.5.2 Receiving sensitivity**
>
> The following table gives typically sensitivity level of the Wireless
> Trackerr-(L/H).

Table3-5-2: Receiving sensitivity

  -------------------------------------------------------------------------
  **Signal                **Spreading Factor**    **Sensitivity/\[dBm\]**
  Bandwidth/\[KHz\]**                             
  ----------------------- ----------------------- -------------------------
  **125**                 SF12                    -134

  **125**                 SF10                    -130

  **125**                 SF7                     -122
  -------------------------------------------------------------------------

> **3.5.3 Operation Frequencies**

Wireless Tracker supports LoRaWAN frequency channels and models
corresponding

> table.

Table3-5-3: Operation Frequencies

  -----------------------------------------------------------------------
  **Region**              **Frequency (MHz)**     **Model**
  ----------------------- ----------------------- -----------------------
  **EU433**               433.175\~434.665        Wireless Tracker-LF

  **CN470**               470\~510                Wireless Tracker-LF

  **IN868**               865\~867                Wireless Tracker-HF

  **EU868**               863\~870                Wireless Tracker-HF

  **US915**               902\~928                Wireless Tracker-HF

  **AU915**               915\~928                Wireless Tracker-HF

  **KR920**               920\~923                Wireless Tracker-HF

  **AS923**               920\~925                Wireless Tracker-HF
  -----------------------------------------------------------------------




> **3.6** **GNSS Characteristics**
>
> **3.6.1 Basic information**

Table3-6-1: Basic information

  -----------------------------------------------------------------------
  **Channel**                         96
  ----------------------------------- -----------------------------------
  **Update frequency**                Max 20 HZ

  **Data format**                     NMEA-0183, Unicore

  **Frequency point**                 BDS: B1l, B1C, B2b, B2a

                                      GPS: L1/L1C, L2C, L5

                                      GLONASS: L1, L2

                                      Galileo: E1B/C, E5b, E5a

                                      QZSS: L1, L2, L5

                                      SBAS: L1

                                      NAVIC: L5
  -----------------------------------------------------------------------

> **3.6.2 Accuracy and TTFF**²

Table3-6-2: Accuracy and TTFF²

  -----------------------------------------------------------------------
  **Positional accuracy(CEP95)**      \<1m
  ----------------------------------- -----------------------------------
  **1PPS**                            15ns

  **Speed accuracy**                  0.1m/s

  **Cold boot**                       24s

  **Warm boot**                       1s

  **Recapture**                       1s
  -----------------------------------------------------------------------



> **3.6.3 Sensitivity (Unit: dBm)**

Talbe3-6-2: Sensitivity

  -------------------------------------------------------------------------------
  **Sensitivity**   **GNSS**    **BDS**     **GPS**     **GAL**     **GLONASS**
  ----------------- ----------- ----------- ----------- ----------- -------------
  **Cold boot**     -148        -146        -148        -144        -144

  **Warm boot**     -156        -155        -155        -154        -148

  **Trace**         -165        -163        -165        -163        -158

  **Recapture**     -156        -154        -156        -154        -152
  -------------------------------------------------------------------------------

> **4. Typical hardware connections**
>
> **4.1** **Physical dimensions**
>
> ![](vertopal_8f318e01667d414e999cf88216ab1739/media/image6.png){width="5.616666666666666in"
> height="4.774998906386702in"}



> **5. Resource**
>
> **5.1** **Relevant Resource**\
>  (Already included Heltec ESP32 LoRaWAN library)\
> \
> 
>
> **5.2** **Contact Information**\
> Heltec Automation Technology Co., Ltd Chengdu, Sichuan, China\
> Email:\
> Phone: +86-028-62374838



![](vertopal_8f318e01667d414e999cf88216ab1739/media/image3.png){width="7.141665573053368in"
height="0.14722222222222223in"}
