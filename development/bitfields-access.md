# Bitfield Accessing

## Bitfield in Control Registers
 * Hardware **control registers** are usually **bitfields**, where **each bit controls a different feature**.

## STM32F4 - DMA_SxCR (Stream x Configuration Register)
|Bit|Name|Description|
|---|---|---|
|0|EN|Stream Enable|
|1|DMEIE|Direct Mode Error Interrupt Enable|
|2|TEIE|Transfer Error Interrupt Enable|
|3|HTIE|Half Transfer Interrupt Enable|

* PFCTRL
* DIR[1:0]
* CIRC
* PINC
* MINC
* PSIZE[1:0]
* MSIZE[1:0]
* PINCOS
* PL[1:0]
* DBM
* CT
* Reserved
* PBURST[1:0]
* MBURST[1:0]
* CHSEL[2:0]
* Reserved



 * When we write:
```c
DMA_CTRL = ( 1 < 0);    /* explicitly sets bit 0 */
```
   * `(1 << 0) = 0b0001     // bit 0`
   * `(1 << 1) = 0b0010     // bit 1`
   * `(1 << 2) = 0b0100     // bit 2`
   * `(1 << 3) = 0b1000     // bit 3`
   * etc.

This makes **which bit we're talking about unambiguous**.  
