; *** VIA VT6102 Rhine II definition ***

; +++ register definition +++
Rhine2_registers	struc
PAR		db	6 dup(?) ; 00 physical address
RxCR		db	?	; 06 receive control
TxCR		db	?	; 07 transmit control
GCR0		db	?	; 08 command 0 (global)
GCR1		db	?	; 09 command 1
		dw	?	; 0a
ISR		dw	?	; 0c interrupt status
IMR		dw	?	; 0e interrupt mask
MAR		dd	?,?	; 10 multicast hash table
CRDA		dd	?	; 18 receive descriptor base
CTDA		dd	?	; 1c transmit descriptor base
		dd	13 dup(?) ; 20-53
GFTRST		db	?	; 54 
RFTCMD		db	?	; 55 
TFTCMD		db	?	; 56 
GFSTATUS	db	?	; 57 
BNRY		dw	?	; 58 
CURR		dw	?	; 5a 
FIFODATA	dd	?	; 5c 
		dd	?,?	; 60 
TallyCntTest	dd	?	; 68 
PHY_ADR		db	?	; 6c 
MIISR		db	?	; 6d 
BCR0		db	?	; 6e bus control 0
BCR1		db	?	; 6f bus control 1
MIICR		db	?	; 70 mii control
MIIADR		db	?	; 71 mii port address
MII_DATA	dw	?	; 72 mii R/W data port
EECSR		db	?	; 74 eeprom control/status
TRST		db	?	; 75 
DEBUG0		db	?	; 76 
DEBUG1		db	?	; 77 
CFGA		db	?	; 78 chip configuration A
CFGB		db	?	; 79 chip configuration B
CFGC		db	?	; 7a chip configuration C
CFGD		db	?	; 7b chip configuration D
TallyCntMPA	dw	?	; 7c 
TallyCntCRC	dw	?	; 7d 
MCR		dw	?	; 80 misc command
PMCPORT		db	?	; 82 PM capability control
STICKHW		db	?	; 83 sticky bit H/W shadow
MISR		db	?	; 84 misc interrupt status
		db	?	; 85
MIMR		db	?	; 86 misc interrupt mask
		db	?	; 87 
		dd	?	; 88 
BPMA		dw	?	; 8c 
		db	?	; 8e 
BPMD		db	?	; 8f 
BPCMD		db	?	; 90 
BPIN_DATA	db	?	; 91 
		db	?	; 92 
EE_CHKSUM	db	?	; 93 
SU_MIIAD	dw	?	; 94 
SU_PHYID	db	?	; 96 
		db	?	; 97 
PauseTimer	dw	?	; 98 
PauseSR		dw	?	; 9a 
Tmr0		dw	?	; 9c 
Tmr1		dw	?	; 9e 
WOLCR_SET	db	?	; a0 WOL command set
PWCFG_SET	db	?	; a1 power configuration set
TESTREG_SET	db	?	; a2 
WOLCG_SET	db	?	; a3 WOL control set
WOLCR_CLR	db	?	; a4 WOL command clear
PWCFG_CLR	db	?	; a5 power configuration clear
TESTREG_CLR	db	?	; a6 
WOLCG_CLR	db	?	; a7 WOL control clear
PWRCSR_SET	db	?	; a8 
		db	3 dup(?) ; a9-ab
PWRCSR_CLR	db	?	; ac 
		db	3 dup(?) ; ad-af
CRC0		dd	?	; b0 CRC pattern 0
CRC1		dd	?	; b4
CRC2		dd	?	; b8
CRC3		dd	?	; bc
ByteMask0	dd	4 dup(?) ; c0 byte mask 0
ByteMask1	dd	4 dup(?) ; d0
ByteMask2	dd	4 dup(?) ; e0
ByteMask3	dd	4 dup(?) ; f0
Rhine2_registers	ends

; --- Receive configuration 06h ---
RRFT		equ	0e0h	; receive FIFO threshold (mask)
PROM		equ	 10h	; all unicast accept
AB		equ	  8	; broadcast accept
AM		equ	  4	; multicast hash hit accept
AR		equ	  2	; runt packet accept
SEP		equ	  1	; CRC errored packet accept

RRFT_64		equ	(000b shl 5)
RRFT_32		equ	(001b shl 5)
RRFT_128	equ	(010b shl 5)
RRFT_256	equ	(011b shl 5)
RRFT_512	equ	(100b shl 5)
RRFT_768	equ	(101b shl 5)
RRFT_1024	equ	(110b shl 5)
RRFT_SF		equ	(111b shl 5)


; --- Transmit configuration 07h ---
RTSF		equ	0e0h	; transmit FIFO threshold (mask)
OFSET		equ	  8	: back-off priority select
LB		equ	  6	; loopback mode (mask)

RTSF_128	equ	(000b shl 5)
RTSF_256	equ	(001b shl 5)
RTSF_512	equ	(010b shl 5)
RTSF_1024	equ	(011b shl 5)
RTSF_SF		equ	(100b shl 5)


; --- control 0  08h ---
RxDMD		equ	40h	; receive poll demand (self clear)
TxDMD		equ	20h	; transmit poll demand (self clear)
TxON		equ	10h	; transmit enable
RxON		equ	 8	; receive enable
STOP		equ	 4	; stop NIC
STRT		equ	 2	; start NIC
INIT		equ	 1	; process begin

; --- control 1  09h ---
SFRST		equ	80h	; software reset (self clear)
RxDMD1		equ	40h	; receive poll demand 1
TxDMD1		equ	20h	; transmit poll demand 1
DPOLL		equ	 8	; disable TD/RD auto polling
FDX		equ	 4	; full duplex mode
EREN		equ	 1	; enable early recieve mode

; --- interrupt status/mask  0ch/0eh ---
GENI		equ	8000h	; general purpose interrupt
SRCI		equ	4000h	; port state change
ABTI		equ	2000h	; excessive collision tx abort
NORBF		equ	1000h	; RD running up
PKTRace		equ	 800h	; receive FIFO queue list overflow
OVFI		equ	 400h	; receive FIFO overflow
UDFI		equ	 200h	; transmit FIFO underflow
ERI		equ	 100h	; early receive
CNT		equ	  80h	; CRC or miss packet counter overflow
BE		equ	  40h	; PCI bus error
RU		equ	  20h	; receive buffer link error
TU		equ	  10h	; transmit buffer underflow
TXE		equ	   8	; transmit error
RXE		equ	   4	; receive error
PTX		equ	   2	; transmit success
PRX		equ	   1	; receive success

I_RX		equ	PRX or RXE or RU or OVFI or PKTRace or NORBF
I_TX		equ	PTX or TXE or TU or UDFI or ABTI

; --- MII configuration  6ch ---
MPO	equ	0e0h	; MII management polling timer interval(mask)
MFDC		equ	 20h	; accelate management data clock speed
PHYAD		equ	 1fh	; PHY device address(mask)

; --- MII status  6dh ---
PHYRST		equ	80h	; PHY reset request by software
PHYOPT		equ	10h	; PHY option. PHY address select.
MIIERR		equ	 8	; PHY device received error
LNKFL		equ	 2	; link fail
SPD10		equ	 1	; medium speed is at 10MB

; --- bus control 0  6eh ---
MED2		equ	80h	; medium select control
EXTLED		equ	40h	; extra LED support control
CRFT		equ	38h	; control rx FIFO threshold? 000:enable RxCR
DMALen		equ	 7	; DMA length (mask)

DMALen_32	equ	000b
DMALen_64	equ	001b
DMALen_128	equ	010b
DMALen_256	equ	011b
DMALen_512	equ	100b
DMALen_1024	equ	101b
DMALen_SF	equ	110b


; --- bus control 1  6fh ---
CTFT		equ	38h	; control tx FIFO threshold? 000:enable TxCR
POT		equ	 7	; Polling Time Interval (mask)

; --- MII control  70h ---
MAUTO		equ	80h	; MII management port auto polling enable
RCMD		equ	40h	; PHY read enable (self clear)
WCMD		equ	20h	; PHY write enable (self clear)
MDPM		equ	10h	; direct programming mode
MOUT		equ	 8	; MDIO output enable indicator
MDO		equ	 4	; data out
MDI		equ	 2	; data in
MDC		equ	 1	; clock

; --- management interface address  71h ---
MIDLE		equ	80h	; MII idle (read only)
MSRCEN		equ	40h	; MII status change enable
MDONE		equ	20h	; pause status/control
MAD		equ	1fh	; MII port address (mask)

; --- EEPROM control/status 74h ---
EEPR		equ	80h	; EEPROM programmed status(read only)
EMBP		equ	40h	; EEPROM embedded program enable
AUTOLD		equ	20h	; dynamic reload EEPROM content
EDPM		equ	10h	; direct program mode
ECS		equ	 8	; chip select
ECK		equ	 4	; clock
EDIN		equ	 2	; data in
EDO		equ	 1	; data out (read only)

; --- chip configuration A  78h ---
EELOAD		equ	80h	; EEPROM embedded and direct programming
MIIOPT		equ	40h	; MII option

; --- chip configuration B  79h ---
QPKTDIS		equ	80h	; transmit frame queuing disable
PERRDIS		equ	40h	; data parity generation and checking disable
MRLDIS		equ	20h	; memory read line disable
TxARBIT		equ	10h	; Tx DMA interleave to Rx DMA
RxARBIT		equ	 8	; Rx DMA interleave to Tx DMA
MRWAIT		equ	 4	; read insert one wait
MWWAIT		equ	 2	; write insert one wait
LATMEN		equ	 1	; latency timer

; --- chip configuration D 7bh ---
MMIOE		equ	80h	; memory mapped IO access enable
DIAG		equ	40h	; diagnostic mode
MRLEN		equ	20h	; memory read line capable
PMCDIG		equ	10h	; PMCC setting test mode
CRADOM		equ	 8	; random backoff algorithm
CAP		equ	 6	; capture effect solution -2 for DEC
MBA		equ	 4	; capture effect solution -1 for AMD
BAKOPT		equ	 1	; backoff algorithm optional

; --- misc control  80h ---
FORSRST		equ	4000h	; force software reset
VAXJMP		equ	2000h	; AUX power
Tm1EN		equ	 100h	; software timer 1 enable
FDXRFEN		equ	   8	; receive full-duplex flow control
HDXFEN		equ	   4	; half-duplex flow control
Tm0Susp		equ	   2	; timer 0 time-out, clear to count
Tm0EN		equ	   1	; software timer 0 enable

; --- sticky hardware 83h ---
LGWOL		equ	80h	; legacy WOL enable status
WOLSR		equ	 8	; legacy WOL status
WOLEN		equ	 4	; legacy WOL enable
DS1		equ	 2	; PCI power mode?
DS0		equ	 1	; 

; --- MII interrupt status/mask  84h/86h ---
PWEI		equ	80h	; power event report
UDPI		equ	40h	; user define
UDPIS		equ	20h	; user define
SSRCI		equ	10h	; suspend well MII polling status change
TDWBR		equ	 8	; TD WB queue race
TM1INT		equ	 2	; software timer 1
TM0INT		equ	 1	; software timer 0

; --- WOL control set/clear  a0h/a4h ---
LinkOFF		equ	80h	; link off
LinkON		equ	40h	; link on
MAGICEN		equ	20h	; magic packet
UNICAST		equ	10h	; unicast
PTNMH3		equ	 8	; pattern 3
PTNMH2		equ	 4	; pattern 2
PTNMH1		equ	 2	; pattern 1
PTNMH0		equ	 1	; pattern 0

; --- Power configuration set/clear  a1h/a5h ---
SMIITIME	equ	80h	; internal MII interface timing
WOLTYPE		equ	20h	; WOL ouput 1:pulse 0:button
LEGCYWOL	equ	10h	; legacy WOL enable
WOL_SR		equ	 2	; legacy WOL_SR shadow
WOL_EN		equ	 1	; legacy WOL_EN shadow

; --- test register? set/clear  a2h/a6h ---
SNORM		equ	1	; all power state capable while PHYTEST=0

; --- WOL configuration set/clear  a3h/a7h ---
PMEOVR		equ	80h	; force PME_EN
SFDX		equ	40h	; full duplex in suspend
SAM		equ	20h	; accept multicast in suspend
SAB		equ	10h	; accept broadcast in suspend
SMIIACC		equ	 8	; MDC acceleration
SMIIOPT		equ	 4	; MIIOPT to extend clock


; +++ transmit / receive descriptor definition +++
; --- transmit descriptor ---
TD	struc
sts	dd	?	; status
ctl	dd	?	; control
buf	dd	?	; buffer address
lnk	dd	?	; next link address
	; --- above for hardware, below for driver
phys	dd	?	; physical address of this descriptor
cnt	dw	?	; number of fragments
vlnk	dw	?	; logical link
TD	ends

; --- receive descriptor ---
RD	struc
sts	dd	?	; status
ctl	dd	?	; control
buf	dd	?	; buffer address
lnk	dd	?	; next link address
	; --- above for hardware, below for driver
vbuf	dd	?	; virtual addresse of buf
phys	dd	?	; physical addresse of this descriptor
tail	dw	?	; tail fragment of the frame
cnt	dw	?	; reserved (number of fragments)
blnk	dw	?	; logical link of protocol
vlnk	dw	?	; logical link
RD	ends

; --- virtual transmit descriptor (for driver) ---
vtxd		struc
head		dw	?	; frame head fragment
tail		dw	?	; frame tail fragment
reqhandle	dw	?	; request handle
protid		dw	?	; protocol id
cnt		dw	?	; number of fragments
vlnk		dw	?	; logical link
immedphys	dd	?	; physical addresse of immediate data buffer
immed		db	64 dup(?) ; reserved buffer for immediate data
vtxd		ends

; --- transmit status bits ---
OWN		equ	80000000h	; owner
TERR		equ	    8000h	; transmit error
SERR		equ	    2000h	; system error
TBUFF		equ	    1000h	; TD error
UDF		equ	     800h	; FIFO underflow
CRS		equ	     400h	; carrier sense lost detect
OWC		equ	     200h	; out of window collision
ABT		equ	     100h	; excessive collision
CDH		equ	      80h	; CD heart beat check failure
COLS		equ	      10h	; collision detect
NCR		equ	      0fh	; # of collision retries (mask)

; --- transmit control bits ---
IC		equ	800000h	; interrupt control
TxEDP		equ	400000h	; packet end    10:end  00:invalid
TxSTP		equ	200000h	; packet start  11:single 01:more
CRC		equ	 10000h	; disable CRC generation
BufCHN		equ	  8000h	; chain structure  1:chain 0:ring

; --- receive status bits ---
;OWN		equ	80000000h
RxLen		equ	7fff0000h	; receive length
RXOK		equ	    8000h	; no receive errors
MAR		equ	    2000h	; multicast
BAR		equ	    1000h	; broadcast
PHY		equ	     800h	; physical match
RxCHN		equ	     400h	; chain, always 1
RxSTP		equ	     200h	; packet start  11:single
RxEDP		equ	     100h	; paclet end  10:more  01:end
BUFE		equ	      80h	; link structure error
RxSERR		equ	      40h	; system error
RxRUNT		equ	      20h	; runt
LONG		equ	      10h	; length > 1518bytes
FOV		equ	       8	; FIFO Overflow
FAE		equ	       4	; frame align error
CRCE		equ	       2	; CRC error
RERR		equ	       1	; receive errors


