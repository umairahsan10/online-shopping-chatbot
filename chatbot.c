#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

int counter = 0;
int total_amount = 0;
int prices[100];
char description[100][100];
int codes[100];
char size_global[100];

struct customer_information
{
	char customer_name[40], customer_email[40], customer_phone[15], shipping_province[15], shipping_city[15], shipping_address[100], billing_province[15], billing_city[15], billing_address[100];
	int shipping_postal_code, billing_postal_code;
}info;

int rand();

int item_bought( char *ptr_description, int *ptr_price, int *ptr_code, char *size )
{
	strcpy( description[counter], ptr_description );
	prices[counter] = *ptr_price;
	total_amount += *ptr_price;
	codes[counter] = *ptr_code;
	size_global[counter] = *size;
	counter++;
	return 0;
}


void save_info (char *name, char *email, char *phone, char *shipping_province, char *shipping_city, char *shipping_address, char *shipping_postal_code, char *billing_province, char *billing_city, char *billing_address, char *billing_postal_code)
{
	FILE *fileptr;
	fileptr= fopen( "Information.txt", "a" );
	if ( fileptr == NULL )
		printf("\nFile could not be opened\n");
	else
	{
		fprintf(fileptr,"\n***********************\n\nCUSTOMER INFORMATION\n-------- -----------\nName : %s \nEMAIL: %s \nPhone: +92%s \n\n 'SHIPPING ADDRESS' \n\nProvince: %s \nCity: %s \nAddress: %s \nPostal Code: %s \n\n 'BILLING ADDRESS' \n\nProvince: %s \nCity: %s \nAddress: %s \nPostal Code: %s \n"
																	, name, email, phone, shipping_province, shipping_city, shipping_address, shipping_postal_code, billing_province, billing_city, billing_address, billing_postal_code );
		fclose(fileptr);
	}
}

int j = 0;

void save_order ( char *description, char *price_code_size)
{
	FILE *fileptr;
	fileptr= fopen( "Information.txt", "a" );
	if ( fileptr == NULL )
		printf("\nFile could not be opened\n");
	else
	{
		if (j == 0)
		{
			fprintf(fileptr, "\n\t\tORDER DETAILS\n\t\t----- --------\n\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE \tSIZE\n---\t\t---- ---- \t\t\t\t\t\t  ----- \t---- \t----\n");
		}
		j++;
		fprintf(fileptr,"%d.\t %s \t Rs.%s \n", j, description, price_code_size );
		fclose(fileptr);
	}
}

int main_call = 0;

int main()
{
	int i;
	
	//INFORMATION OF KIDS CLOTHING:
	//INFORMATION FOR BOYS CLOTHINGS(KIDS):
	//INFOMATION OF BOYS TOPS CLOTHING(KIDS SECTION):
	char kids_boys_tops_hoodies_and_sweatshirts[15][100] = {"BOYS SWEATSHIRT SKATE - WINTER White                       " , "TODDLER BOYS DENIM JACKET HOGWARTS -LIGHT BLUE             " , "BOYS HOODED KNITTED JACKET - BLUE                          " , "BOYS SWEATSHIRT CARTOON PRINT- JET BLACK                   " , "BOYS HOODED KNITTED JACKET RENOUNCE - ORANGE               " , "BOYS SWEATSHIRT GALAXY - NAVY                              " , "BOYS SWEATSHIRT LION KING - BROOK GREEN                    " , "BOYS SWEATSHIRT CHARACTER - BLACK                          " , "BOYS KNITTED JACKET - GREEN                                " , "BOYS CHARACTER SWEATSHIRT - MAROON                         " , "BOYS HOODED KNITTED JACKET REFLECTIVE - CHARCOAL           " , "BOYS HOODED SHIRT H&S - RED CHECK                          " , "BOYS HOODED SHIRT - GREEN CHECK                            " , "BOYS SWEATSHIRT ROUND NECK - PEACH                         " , "BOYS HOODED KNITTED JACKET - WHITE                         "};
	//HOODIES AND SWEAT SHIRTS.
	int kids_boys_tops_hoodies_and_sweatshirts_prices[15] = {1195, 1895, 1495, 995, 1395, 1095, 995, 995, 1495, 995, 1395, 1395, 1395, 1095, 1395};
	int kids_boys_tops_hoodies_and_sweatshirts_codes[15];
	
	char kids_boys_tops_kurta_and_shalwar_kameez[15][100] = {"BOYS KURTA DECENT-GREEN                                    " , "BOYS BASIC JACQUARD KURTA - POWDER BLUE                    " , "BOYS KURTA SLUB - WAX YELLOW                               " , "BOYS KURTA PRIME - CREAM              	                    " , "BOYS EMBROIDERED KURTA ELEGANT POCKET - MINT               " , "BOYS DIGITAL PRINT KURTA DECENT - BLUE                     " , "BOYS DOBBY KURTA BABOON-NAVY                               " , "BOYS EMBROIDERED KURTA - GREY                              " , "BOYS EMBROIDERED 3PCS SUIT - PEACH                         " , "BOYS PRINTED 3 PCS SUIT MINT JULIP-LT.BLUE                 " , "BOYS PRINTED KURTA BLACK PEARL-BLACK                       " , "BOYS BASIC KURTA F2 - PURPLE                               " , "BOYS DIGITAL PRINT KURTA-CITRUS                            " , "BOYS PLAIN SLUB KURTA PAJAMA - OFF-WHITE                   " , "EMBROIDERED KURTA                                          "};
	//KURTA AND SHALWAR KAMEEZ;
	int kids_boys_tops_kurta_and_shalwar_kameez_prices[15] = {1295, 1195, 1195, 1395, 1495, 1299, 1499, 1395, 3895, 3895, 1495, 1195, 1295, 1795, 1299};
	int kids_boys_tops_kurta_and_shalwar_kameez_codes[15];
	
	char kids_boys_tops_sets_and_suits[15][100] = {"BOYS 2 PCS SUIT CHARACTER- BLACK                           " , "BOYS 2 PCS SUIT NAVY CAMOUFLAGE - NAVY BLUE                " , "BOYS 2 PCS SUIT CREATIVE MOOD - TIE DYE                    " , "UNISEX THERMAL SUIT - YELLOW                               " , "ACTION HERO SPIDERMAN BOYS 2 PCS F/S SUIT                  " , "BOYS KNITTED 2PCS SUIT NIGHT WEAR - WHITE                  " , "TEENS BOYS 2 PCS SUIT FUTURE IS NOW - GREY/ORANGE          " , "TEENS BOYS 2 PCS SUIT READY TO START - BLACK               " , "BOYS 2 PCS SUIT CAMO FLASH-GRAY                            " , "BOYS 2 PCS SUIT FURTHER FASTER - GRAY                      " , "BOYS 2 PCS SUIT CHARACTER PRINT -BLACK                     " , "BOYS 2 PCS SUIT TIGERS - GRAY                              " , "RACING CARS BOYS 2 PCS F/S SUIT - RED/WHITE                " , "BOYS 2 PCS SUIT FOREVER-GREEN                              " , "UNISEX THERMAL SUIT - BLUE                                 "};
	//BOYS SETS AND SUITS;
	int kids_boys_tops_sets_and_suits_prices[15] = {1895, 2195, 1895, 1295, 1395, 1495, 2495, 2495, 2195, 1895, 1495, 1595, 1395, 2195, 1295};
	int kids_boys_tops_sets_and_suits_codes[15];
	
	char kids_boys_tops_coats_and_jackets[15][100] = {"BOYS LEATHER JACKET BIKER SLEEVES-BLACK                    " , "BOYS QUILTED ZIPPER JACKET -NAVY                           " , "BOYS HOODED LEATHER JACKET - BROWN                         " , "BOYS HOODED JACKET DIP DYE                                 " , "BOYS HOODED JACKET CORE - SILVER/BLACK                     " , "BOYS QUILTED JACKET BASIC F/S-CITRUS                       " , "JUNIOR BOYS DENIM JACKET HOGWARTS -LIGHT BLUE              " , "BOYS COTTON JACKET NEVER REST - RED                        " , "BOYS KNITTED JACKET NASA - GREEN                           " , "STYLISH BOYS HOODED WINTER TRENCH COAT WARM OUTWEAR - BLACK" , "BOYS HOODED JACKET CHARACTER - BLACK                       " , "BOYS DENIM JACKET BASIC - BLACK                            " , "TEENS BOYS LEATHER JACKET TEENS - BLACK                    " , "BOYS KNITTED JACKET RENOUNCE - SHARP GREEN                 " , "BOYS DENIM JACKET ACTION HERO - BLUE                       "};
	int kids_boys_tops_coats_and_jackets_prices[15] = {4795, 2795, 4795, 3295, 3595, 2795, 1955, 2295, 1395, 2995, 2095, 1695, 5995, 1395, 2295};
	int kids_boys_tops_coats_and_jackets_codes[15];
	
	char kids_boys_tops_printed_tees[15][100] = {"UNISEX T-SHIRT BOOM BOOM - Green                           " , "UNISEX T-SHIRT H/S WORLD CUP FEVER - GREEN                 " , "BOYS T-SHIRT F/S SOLAR SYSTEM - SKY Blue                   " , "BOYS T-SHIRT ACTION HERO - Charcoal                        " , "BOYS CHARACTER T-SHIRT - SAFFRON                           " , "BOYS POLO GRYFFINDOR - RED                                 " , "BOYS T-SHIRT CARTOON SCOOBY-DOO PRINT- GREEN               " , "BOYS T-SHIRT F/S KICK FLIP - JET-BLACK                     " , "BOYS POLO UNION 10 - GREEN/LEMON                           " , "BOYS T-SHIRT CARTOON CHARACTER PRINT - WHITE               " , "BOYS T-SHIRT SPIDEY - B. WHITE                             " , "TEENS BOYS T-SHIRT F/S THE JOKER - B.WHITE                 " , "BOYS T-SHIRT DARK KNIGHT - LIGHT CREAM                     " , "BOYS T-SHIRT FOSSIL FINDER - LIGHT BEIGE                   " , "BOYS POLO SHIRT - LEMON                                    " };
	int kids_boys_tops_printed_tees_prices[15] = {895, 995, 795, 795, 795,  1195, 795, 995, 1195, 795, 795, 1095, 895, 995, 1195};
	int kids_boys_tops_printed_tees_codes[15];
	
	char kids_boys_bottoms_jeans[15][100] = {"TEENS BOYS PANT DENIM CUT & SEW - DARK BLUE                " ,"BOYS PANT DENIM CUT & SEW - DARK BLUE                      " ,"TEENS BOYS PANT DENIM CUT & SEW - ICE BLUE                 " ,"BOYS PANT DENIM SUMMER - LIGHT GREY                        " ,"BOYS PANT DENIM EMB - DARK GREY                            " ,"BOYS PANT DENIM PANELS - BLACK                             " ,"WEEKEND SCORE DENIM PANT FOR BOYS - BLACK                  " ,"BOYS PANT DENIM CARGO - CHARCOAL GREY                      " ,"BOYS PANT DENIM CHARACTER - ICE BLUE                       " ,"BOYS PANT DENIM AMAZING-MUSTARD                            " ,"BOYS DENIM PANT CHARACTER PRINT- ICE BLUE                  " ,"BOYS PANT DENIM UNLIMITED - MID BLUE                       " ,"BOYS PANT DENIM APPLIQUE - L GREY                          " ,"BOYS PANT DENIM RIPPED ON KNEE - GREY                      " ,"BOYS PANT DENIM TAPE - LIGHT BLUE                          "};
	int kids_boys_bottoms_jeans_prices[15] = {1695, 1395, 1295, 1695, 1295, 1195, 1395, 1595, 1495, 1695, 1395, 1595, 1295, 1495, 1695};
	int kids_boys_bottoms_jeans_codes[15];
	
	char kids_boys_bottoms_shorts[15][100] = {"BOYS SHORT COTTON RHINO PARK - GREEN                       ","BOYS SHORT COTTON RUN - BLACK                              ","BOYS SHORT COTTON TROPICAL - CORAL                         ","BOYS SHORT COTTON BASIC S5 - LT.GREEN                      ","BOYS SHORT COTTON STRIPER - ORANGE                         ","BOYS BOXER PACK OF 3 - (BLACK, GREEN, WHITE)               ","BOYS PINE APPLE COTTON SHORT - LIGHT PINK                  ","BOYS SHORT KNITTED STRIPER - PEACH                         ","BOYS SHORT COTTON SD-01 - L. GREEN                         ","BEACH PRINT DENIM SHORT FOR BOYS - MID BLUE                ","BOYS SHORT COTTON GAME ON - BLACK                          ","BOYS SHORT COTTON PARADISE ISLAND                          ","BOYS SHORT JACQUARD - KHAKI                                ","BOYS BOXER PACK OF 3-(WHITE, PINK, ORANGE)                 ","MUSIC PRINT COTTON SHORT FOR BOYS - B.BLUE                 "};
	int kids_boys_bottoms_shorts_prices[15] = {885, 795, 695, 995, 895, 1295, 1095, 885, 995, 1495, 1095, 995, 1095, 1495, 995};
	int kids_boys_bottoms_shorts_codes[15];
	
	char kids_boys_bottoms_pyjamas_and_trousers[15][100] = {"BOYS JERSEY PYJAMA - SAFFRON                               " ,"BOYS PAJAMA BASIC - GREY                                   " ,"BOYS PAJAMA BASIC - BLUE                                   " ,"BOYS TROUSER COTTON CHEMO P - GREEN                        " ,"BOYS TROUSER COTTON CHEMO P - GREY                         " ,"BOYS TERRY AND FLEECE PYJAMA FRIENDS - NAVY BLUE           " ,"BOYS TERRY AND FLEECE PYJAMA SINGLE POCKET - AQUA          " ,"BOYS EASTERN BASIC PAJAMA - BLACK                          " ,"BOYS JERSEY PYJAMA CAMO - GREEN                            " ,"PRINTED BOYS PAJAMA WITH SOFT RIP BORN TO HOOP-CITRUS      " ,"BOYS TERRY AND FLEECE PAJAMA ATHLETIC - GREY               " ,"CHARACTER PRINT BOYS TERRY AND FLEECE PAJAMA - GREEN       " ,"BOYS TERRY AND FLEECE PAJAMA LOGO PRINT - CHARCOAL         " ,"BOYS TERRY AND FLEECE PYJAMA CHARACTER - BURGUNDY          " ,"BOYS EASTERN BASIC PAJAMA - WHITE                          " };
	int kids_boys_bottoms_pyjamas_and_trousers_prices[15] = {795, 695, 695, 1495, 1495, 1095, 995, 595, 1095, 1195, 1095, 1195, 1095, 995, 595};
	int kids_boys_bottoms_pyjamas_and_trousers_codes[15];
	
	
	char kids_girls_tops_jackets_and_sweatshirts[15][100] = {"GIRLS SWEATSHIRT CHARACTER - W-WHITE                       ",	"GIRLS SWEATSHIRT POSITIVE - LIGHT PINK                     ",	"GIRLS SWEATSHIRT FLOWER - SEA GREEN                        ",	"GIRLS SWEATSHIRT DREAM BIG - SKY BLUE                      ",	"GIRLS WINTER SWEATSHIRT RAINBOW - BLACK                    ",	"GIRLS SWEATSHIRT BUTTERFLY - ANTI/WHITE                    ","GIRLS HOODED JACKET CHARACTERS PRINTED - CREAM             ", "GIRLS SWEATSHIRT CHARACTER - TIE DYE                       ", "GIRLS SWEATSHIRT FUN TOGETHER - SKY BLUE                   ", "GIRLS KNITTED FUR JACKET - PINK                            ", "GIRLS SWEATSHIRT DREAM BIG - NAVY                          ", "GIRLS SWEATSHIRT BE KIND - YELLOW                          ", "GIRLS QUILTED ZIPPER JACKET BASIC - PINK                   ", "GIRLS PUFFER JACKET MOON LESS - BLACK                      ", "PULL OVER HOODED JACKET FOR GIRLS - OLIVE                  "}; 
	int kids_girls_tops_jackets_and_sweatshirts_prices[15] = {1295, 1895, 1395, 1295, 1895, 1795, 1895, 1295, 1395, 2495, 1895, 1795, 2795, 2995, 995};
	int kids_girls_tops_jackets_and_sweatshirts_codes[15];
	
	char kids_girls_tops_sets_and_suits[15][100] = {"GIRLS DIGITAL PRINTED JUMPSUIT - MIX                       ", "GIRLS JUMPSUIT WHITE DOTS - CANDY PINK                     ", "GIRLS KNITTED NIGHT SUIT DREAM QUEEN-A-CREAM               ", "GIRLS KNITTED NIGHT SUIT SLEEPING BEAUTY                   ", "GIRLS KNITTED NIGHT SUIT GOOD NIGHT - LEMONADE             ", "GIRLS KNITTED NIGHT SUIT DO NOT DISTURB - CITRUS/BLUE CHECK", "GIRLS 2PCS TOP PAJAMA - MULTI                              ", "GIRLS DIGITAL PRINT JUMPSUIT - MULTI                       ", "GIRLS NIGHT WEAR SUIT SHINE LIKE                           ", "UNISEX THERMAL SUIT - GREEN                                ", "GIRLS 2 PCS NIGHT WEAR SUIT                                ", "TEENS GIRLS 2 PCS SUIT NO BAD VIBES - BEIGE                ", "GIRLS 2 PCS SUIT DON'T STOP - TIE DYE                      ", "GIRLS KNITTED NIGHT SUIT LOVE TO SLEEP - OFF WHITE/PINK    ", "GIRLS 2 PCS SUIT GOOD TIMES - BLACK                        "};
	int kids_girls_tops_sets_and_suits_prices[15] = {1595, 1695, 1295, 995, 1295, 1495, 1195, 1295, 1395, 1895, 1495, 1495, 1595, 2095, 2195};
	int kids_girls_tops_sets_and_suits_codes[15];
	
	char kids_girls_tops_frocks[15][100] = {"GIRLS FLANNEL FROCK - RED                                  ", "GIRLS FANCY FROCK POLKA DOTS SEQUINS BELT - CREAM          ", "GIRLS FANCY FROCK POLKA DOTS SEQUINS BELT - HOT PINK       ", "GIRLS FANCY FROCK FLOWERS - GREEN                          ", "GIRLS FANCY FROCK FLOWERS - DARK PINK                      ", "GIRLS FANCY FROCK AOP BUTTERFLY - WHITE                    ", "GIRLS FANCY FROCK SEQUINS - GOLDEN                         ", "GIRLS FANCY FROCK FLOWER BROSCH - SEA GREEN                ", "GIRLS FANCY FROCK FLOWER BROSCH - BEIGE                    ", "GIRLS FROCK FANCY LAYERED VELVET SEQUINS                   ", "GIRLS FANCY FROCK RUFFLE - PURPLE                          ", "GIRLS FROCK PRINTED MULTI - PRINTED                        ", "GIRLS FROCK PRINTED MULTI - PRINTED                        ", "GIRLS FANCY FROCK SHIMMER STARS –-MULTI                    "};
	int kids_girls_tops_frocks_prices[15] = {2495, 2595, 2595, 4195, 3195, 2095, 3595, 4095, 2595, 2695, 3595, 2795, 3495, 3095, 2095};
	int kids_girls_tops_frocks_codes[15];
	
	char kids_girls_bottoms_pants_and_leggings[15][100] = {"GIRLS JEGGING COTTON BIG STRAWBERRY - WHITE                ", "GIRLS JEGGING COTTON ICE CREAM - MULTI                     ", "GIRLS JEGGING COTTON RAINBOW - WHITE                       ", "GIRLS JEGGING COTTON LEAVES                                ", "GIRLS PANT DENIM STAR - GREY                               ", "GIRLS TROUSER PLEATS - BEIGE                               ", "GIRLS PANT DENIM PEARLS - BLUE                             ", "GIRLS PAJAMA MAGICAL - LIME                                ", "GIRLS PANT DENIM FLOWER EMB BUNCH - LIGHT GREY             ", "GIRLS PANT DENIM FLOWER EMB BUNCH - LT.BLUE                ", "GIRLS COTTON JEGGING PRINTED - BLACK                       ", "GIRLS PANT DENIM F/SLIT BELL BOTTOM - ICE BLUE             ", "GIRLS PANT DENIM HEM POMPOM LACE - MID BLUE                ", "SHALWAR FOR GIRLS - BLACK                                  ", "CORDUROY PANT FOR GIRLS - GOLD FUSION                      "};
	int kids_girls_bottoms_pants_and_leggings_prices[15] = {795, 595, 995, 895, 1095, 895, 1295, 495, 1195, 1095, 695, 1395, 1095, 1295, 1195};
	int kids_girls_bottoms_pants_and_leggings_codes[15];
	
	char kids_girls_bottoms_socks_and_tights[15][100] = {"GIRLS RIB TIGHTS - PINK                                    ",	"GIRLS TIGHTS - SKY BLUE                                    ",	"GIRLS TIGHTS - BLUE                                        ","GIRLS TIGHTS - AQUA                                        ","GIRLS SOCKS 2PCS HEARTS - PINK	                            ",	"GIRLS TIGHT BASIC - PINK                                   ","GIRLS TIGHTS YARN DYED - BLUE WHITE                        ","GIRLS TIGHTS PRINTED HEART - NAVY                          ",	"GIRLS TIGHTS PRINTED SMALL HEART - PRINTED                 ",	"PRINTED GIRL TIGHTS STAR - NAVY                            ",	"GIRLS BASIC TIGHTS - CHERRY                                ","GIRLS TIGHTS PRINTED SMALL HEART                           ","GIRLS RIB TIGHTS - PEACH                                   ",	"GIRLS BASIC TIGHTS - WHITE                                 ","GIRLS SEQUINS TAPE TIGHTS E.C - SAFFRON                    "};
	int kids_girls_bottoms_socks_and_tights_prices[15] = {595, 595, 595, 595, 795, 595, 695, 695, 595, 895, 795, 595, 595, 595, 795};
	int kids_girls_bottoms_socks_and_tights_codes[15];
	
	char kids_girls_bottoms_shorts_and_skirts[15][100] = {"GIRLS DIGITAL PRINT SHORT SKIRT FLOWER - MULTI	            ",	"BLACK NIGHT DIGITAL PRINT LONG SKIRT FOR GIRLS - BLACK     ",	"PLEAT SHORT SKIRT FOR GIRLS - MAROON                       ","GIRLS SKIRT NEON STAR APPLIQUE - NEON ORANGE               ","GIRLS DIGITAL PRINT LONG SKIRT JASMINE - YELLOW            ","GIRLS DIGITAL PRINT LONG SKIRT - MULTI                     ",	"GIRLS SHORT SKIRT MULTI DOTS - WHITE                       ",	"GIRLS CHIFFON SHORT SKIRT TIE & DYE                        ",	"GIRLS LONG SKIRT BLACK DOTS - WHITE                        ",	"GIRLS SHIRT CASUAL SKIRT TIE DYE                           ",	"GIRLS DIGITAL PRINT LONG SKIRT - MULTI                     ","GIRLS RAINBOW PRINT SHORT SKIRT                            ","GIRLS DIGITAL PRINT LONG SKIRT - NAVY                      ","GIRLS SKIRT NET FRILL - NEON GREEN                         ","NET FRILL SKIRT FOR GIRLS - BLUE                           "};
	int kids_girls_bottoms_shorts_and_skirts_prices[15] = {895, 1295, 895, 995, 1295, 1295, 795, 795, 895, 795, 795, 995, 995, 695, 995};
	int kids_girls_bottoms_shorts_and_skirts_codes[15];
	
	//INFORMATION OF TEENS CLOTHING: 
	
	//INFORMATION OF TEEN BOYS:
	char teen_boys_top_shirts_tshirts[15][100]={"Blue Sport Polo                                            ", "Grey Navy Sports Polo                                      ", "Red Sports Polo                                            ", "Charcoal Sports Polo                                       ", "Maroon Yarn Dyed Polo                                      ", "Sapphire Sports Polo                                       ", "Glacier Grey Signature Polo                                ", "Multi-Color Yarn Dyed Polo                                 ", "Olive Signature Polo                                       ", "Blue Striped Casual Shirt                                  ", "Pink Basic Smart Casual                                    ", "Multi-Color Checkered Casual Shirt                         ", "Sky White Striped Casual Shirt                             ",  "Brown Casual Shirt                                         ", "Purple Striped Smart Casual Shirt                          "};
	//TEENS BOYS SHIRTS AND T-SHIRTS;
	int	teen_boys_top_shirts_tshirts_price[15]={1650, 1350, 1520, 1380, 1500, 1610, 1190, 1340, 1220, 1620, 1340, 2100, 1800, 2990, 2020}; //TEENS BOYS SHIRST AND T-SHIRTS;
	int teen_boys_top_shirts_tshirts_code[15];
	
	char teen_boys_tops_hoodies_sweatshirts[15][100]={"Ecru Basic Quarter Zip Mock Neck SweatShirt                ", "Heather Grey Basic Zipper                                  ","Navy Color Block Zip Up                                    ", "Color Block Pullover Hoodie                                ", "Grey Basic SweatShirt                                      ","Maroon Basic Zip Up Hoodie                                 ", "Multi Color Block SweatShirt                               ", "Navy Basic Mock Neck SweatShirt                            ", "Brown Basic Zipper Hoodie                                  ", "Heather Grey Color Block Zipper Hoodie                     ", "Black Basic SweatShirt                                     ", "Lavender Basic Crew Neck SweatShirt                        ", "Khaki Brown Pull Over Hoodie                               ", "Navy Blue Pull Over Hoodie                                 ", 	"Grey Basic Mock Neck SweatShirt                            "};
	//TEENS BOYS HOODIES AND SWEAT SHIRTS
	int teen_boys_tops_hoodies_sweatshirts_price[15]={2280, 2260, 2600, 3000, 2990, 2380, 2640, 2630, 2220, 2690, 2640, 2100, 2090, 2700, 2840};// TEENS BOYS HOODIES AND SWEAT SHIRT PRICE;
	int teen_boys_tops_hoodies_sweatshirts_code[15];
	
	char teen_boys_tops_kurta_shalwar[15][100]={"DENIM BLUE BLENDED KAMEEZ SHALWAR                          ","WHITE BLENDED KAMEEZ SHALWAR                               ","LIGHT BROWN COTTON KURTA PAJAMA                            ","PALE BLUE COTTON KURTA PAJAMA                              ","MIDNIGHT BLUE BLENDED KURTA PAJAMA                         ","PURPLE BLENDED KURTA PAJAMA                                ","WHITE BLENDED KAMEEZ SHALWAR                               ","BLACK BLENDED KAMEEZ SHALWAR                               ","NAVY BLUE BLENDED KAMEEZ SHALWAR                           ","CEDAR BLENDED KAMEEZ SHALWAR                               ","DENIM BLENDED KURTA PAJAMA                                 ","GREYISH GREEN BLENDED KURTA PAJAMA                         ","BLACK BLENDED KAMEEZ SHALWAR                               ","MEHNDI GREEN BLENDED KAMEEZ SHALWAR                        ","MAROON BLENDED KAMEEZ SHALWAR                              "};
	//TEEN BOYS KURTA SHALWAR;
	int teen_boys_tops_kurta_shalwar_price[15]={3999, 3490, 5190, 5190, 4990, 4490, 3790, 3790, 4490, 4190, 3790, 4390, 4490, 4490, 4990};//TEEN BOYS KURTA SHALWAR PRICE;
	int	teen_boys_tops_kurta_shalwar_code[15];
	
	//INFORMATION OF TEEN BOYS BOTTOM:
	char teen_boys_bottom_dress_pants[15][100]={"Sand Basic Dress Pant                                      ","Navy Basic Dress Pant                                      ","Dark Brown Basic Dress Pant                                ","Dark Grey Basic Dress Pants                                ","Black Basic Dress Pants                                    ","Navy Basic Dress Pants                                     ","Charcoal Basic Dress Pants                                 ","Black Basic Dress Pants                                    ","Navy Basic Dress Pants                                     ","Ash Grey Basic Dress Pants                                 ","Steel Grey Flexi Dress Pants                               ","Grey Basic Dress Pants                                     ","Dark Grey Basic Dress Pants                                ","Brown Basic Dress Pants                                    ","Dark Brown Dress Pants                                     "};
	//TEEN BOYS DRESS PANTS;
	int teen_boys_bottom_dress_pants_price[15]={2090, 2100, 3600, 3700, 2240, 2140, 2750, 3050, 2750, 3650, 2650, 2850, 2670, 3250, 2950,};//TEAN BOYS DRESS PANTS PRICE
	int teen_boys_bottom_dress_pants_code[15];
	
	char teen_boys_bottom_jeans[15][100]={"Medium Blue Basic Jeans                                    ","Navy Basic Non-Denim Jeans                                 ","Brown Basic Non-Denim Jeans                                ","light blue Basic Jeans                                     ","Black Basic Jeans                                          ","Medium Wash Basic Jeans                                    ","Dark Blue Basic Jeans                                      ","Navy Non-Denim Jeans                                       ","Grey Basic Jeans                                           ","Light blue Basic Jeans                                     ","Dark Blue Basic Jeans                                      ","Dark Wash Basic Jeans                                      ","Plain Basic Jeans                                          ","Olive Basic Non Denim Jeans                                ","White Basic Jeans                                          "};
	//TEEN BOYS JEANS;
	int	teen_boys_bottom_jeans_price[15]={2090, 2100, 2270, 2280, 2150, 2250, 2140, 1650, 2130, 2280, 1990, 2250, 2130, 2000, 2110};
	int teen_boys_bottom_jeans_code[15];
	
	char teen_boys_bottom_shorts[15][100]={"White Basic Shorts                                         ","Black Basic Short                                          ","Charcoal Basic Shorts                                      ","Olive Basic Shorts                                         ","Light blue Basic Shorts                                    ","Sky Basic Knitted Shorts                                   ","Med Blue Basic Shorts                                      ","Camel Basic Shorts                                         ","Dark Blue Basic Shorts                                     ","Dark Brown Basic Shorts                                    ","Navy Blue Basic Shorts                                     ","Light Grey Basic Shorts                                    ","Ash Grey Basic Shorts                                      ","Navy Basic Shorts                                          ","Charcoal Basic Shorts                                      "};
	//TEEN BOYS SHORTS;
	int teen_boys_bottom_shorts_price[15]={1220, 1400, 1490, 1310, 1300, 1320, 1490, 1500, 1680, 1670, 1480, 1320, 1310, 1280, 1550}; //TEEN BOYS SHORTS PRICE
	int teen_boys_bottom_shorts_code[15];
	
	
	//INFORMATION OF TEEN GIRLS CLOTHING:
	char teen_girls_top_kurtis[15][100]={"BLUE JACQUARD KURTI                                        ","NAVY BLUE VISCOSE KURTI                                    ","BROWN COTTON KURTI                                         ","MUSTARD COTTON KURTI                                       ","MAROON VELVET KURTI                                        ","BLACK VELVET KURTI                                         ","GREY KHADDAR KURTI                                         ","PURPLE-GREY KHADDAR KURTI                                  ","MAROON LAWN KURTI                                          ","BLACK LAWN KURTI                                           ","GREEN LAWN KURTI                                           ","BEIGE LAWN KURTI                                           ","RED-PINK KHADDAR KURTI                                     ","MUSTARD-BLACK KHADDAR KURTI                                ","YELLOW KARANDI KURTI                                       "};
	//TEEN GIRLS KURTIS
	int teen_girls_top_kurtis_price[15]={4450, 3990, 4500, 3400, 4400, 4500, 4390, 3490, 4490, 4590, 3990, 3890, 4550, 3450, 4490};		//PRICE KURTIS
	int teen_girls_top_kurtis_code[15];
	
	char teen_girls_top_tees[15][100]={"BLACK PREMIUM CUT GIRLS SLEEVELESS TEE                     ","MAROON PREMIUM CUT GIRLS SLEEVELESS TEE                    ","OLIVE GREEN PREMIUM CUT GIRLS SLEEVELESS TEE               ","NAVY PREMIUM CUT GIRLS SLEEVELESS TEE                      ","LIMITED EDITION RED GIRLS V-NECK TOP                       ","TEAL BLUE PREMIUM CUT GIRLS SLEEVELESS TEE                 ","SWEATY HAIR DONT CARE V-NECK GIRLS TOP                     ","EXCUSES DONT BURN CALORIES BLACK V-NECK GIRLS TOP          ","RUN FASTER BLACK V-NECK GIRLS TOP                          ","BASIC CHARCOAL PREMIUM CUT GIRLS COTTON TEE                ","SOMETIMES YOU WIN FULL SLEEVE GIRLS TEE                    ","FITISH PINK GIRLS TANK                                     ","RISE & GRIND GIRLS TEE                                     ","LIFE IS TOUGH OLIVE GIRLS TANK                             ","FEEL THE BURN BLACK V-NECK GIRLS TOP                       "};
	//TEEN GIRLS TEES
	int teen_girls_top_tees_price[15] = {1185,1185,1185,1185,1585,1185,1585,1385,1485,1385,1185,1285,1385,1185,1385}; 	//PRICES TEES
	int teen_girls_top_tees_code[15];
	
	char teen_girls_top_hoodies_sweatshirts[15][100]={"Cream New York Full Zip Hoodie Purple                      ","Sparkle Pacific Sunwear Crew Neck Sweatshirt Blue          ","Snowflake Tile Half Snap Sherpa Fleece Sweatshirt Ice Blue ","Mushroom Crew Neck Sweatshirt Brown                        ","Mermaid Crest Crew Neck Sweatshirt Olive                   ","Jumbo Mickey & Minnie Crew Neck Sweatshirt White           ","Groovy Floral Half Snap Sherpa Fleece Sweatshirt           ","Cosmic Cowgirl Crew Neck Sweatshirt - Black                ","Wonder Seeker Crew Neck Sweatshirt Orange                  ","Black Full Zip Hoodie                                      ","Heather Grey Full Zip Hoodie                               ","Blue Full Zip Hoodie                                       ","White New York Full Zip Hoodie                             ","Mind On The Mountain Oversized Sweatshirt Cream            ","Groovy Floral Cropped Sherpa Hoodie Brown                  "};
	//TEEN GIRLS HOODIE
	int teen_girls_top_hoodies_sweatshirts_price[15] = {3400,3500,3500,3550,3450,3999,3850,3650,3750,3750,4050,3550,3750,4200,4250};	//PRICES HOODIE
	int teen_girls_top_hoodies_sweatshirts_code[15];
	
	
	// INFORMATION OF TEEN GIRLS BOTTOMS:
	
	char teen_girls_bottom_jeans[15][100]={"Dark Blue Baggy Cargo Pants                                ","Vanilla Baggy Cargo Pants                                  ","Brownie Utility Cargo Pants                                ","Black Baggy Cargo Pants                                    ","Eco Dark Blue Ripped Dad Jeans                             ","Black High Waisted Jeggings                                ","Eco Purple High Waisted Flare Jeans                        ","Brown Corduroy High Waisted Bootcut Jeans                  ","Brown High Waisted Bootcut Jeans                           ","Eco Gray Ripped Jeans                                      ","Surplice V Waist Flare Yoga Pants                          ","Eco Medium Blue High Waisted Straight Leg Jeans            ",	"Eco Light Blue Jeans                                       ","Dark Blue Slit High Waisted Bootcut Jeans                  ","Purple Corduroy High Waisted Bootcut Jeans                 "};
	//TEEN GIRLS JEANS
	int teen_girls_bottom_jeans_price[15] = {3000, 4500, 4590, 5000, 4999, 4790, 4990, 4900, 3900, 4400, 4690, 3499, 4599, 3999, 4590};		//PRICES JEANS
	int teen_girls_bottom_jeans_code[15];
	
	char teen_girls_bottom_shalwar[15][100]={"Maroon shalwar on cotton fabric                            ","Green shalwar on slub fabric                               ","A resplendent blue shalwar                                 ","A lovely beige shalwar                                     ","A magenta tulip shalwar                                    ","Off-white tulip shalwar on cotton tencel fabric            ","Cream tulip shalwar with running embroidery at the bottom  ","Green shalwar on slub linen fabric                         ","Sage green shalwar                                         ","dark blue raw silk shalwar                                 ","Sea green lawn shalwar                                     ","Beige and orange tulip shalwar                             ","Green cambric shalwar                                      ","Basic grey shalwar for daily wear                          ","Black linen tulip shalwar                                  "};
	//TEEN GRILS SHALWAR
	int teen_girls_bottom_shalwar_price[15] = {1500,1400,1499,1599,890,1500,1499,1799,1899,1699,1100,1200,1200,1200,1499};		//PRICES SHALWAR
	int teen_girls_bottom_shalwar_code[15];
	
	char teen_girls_bottom_trousers[15][100]={"BLACK LEGGING WITH TWO PRINTED STRIPES AND LOGO            ","DARK GREY LEGGING WITH TWO PRINTED STRIPES AND LOGO        ","BLACK HIGH WAISTED GIRLS TROUSER                           ","NAVY HIGH WAISTED GIRLS TROUSER                            ","TEA PINK HIGH WAISTED GIRLS TROUSER                        ","TIGER ORANGE HIGH WAISTED GIRLS TROUSER                    ","BLACK LEGGINGS WITH RED FADED PANEL                        ","BLACK LEGGINGS WITH YELLOW AND WHITE STRIPE                ","DOUBLE PIPING BLACK GIRLS LEGGINGS                         ","BLUE HIGH WAISTED GIRLS PREMIUM LEGGINGS                   ","GREY TEXTURED HIGH WAISTED GIRLS PREMIUM LEGGINGS          ","THE PERFECT BROWN CARGO BOTTOMS                            ","BLACK HIGH WAISTED PREMIUM POCKET LEGGINGS                 ","GREY WHITE PREMIUM RELAX FIT VISCOSE BOTTOMS               ","BLACK HIGH WAISTED LEGGINGS WITH SIDE WHITE PANEL          "};//TEEN GIRLS TROUSERS
	int teen_girls_bottom_trousers_price[15] = {2350,2350,2150,2350,2150,1850,1950,2350,2150,2150,2350,2250,1950,1950,2350};		//PRICES TROUSERS
	int teen_girls_bottom_trousers_code[15];
	
	//INFORMATION OF ADULTS CLOTHING:
	
	// INFORMATION OF MEN'S CLOTHING:
	//INFORMATION OF MEN'S TOPS:
	char men_top_casual_shirts[15][100]={"MEN'S WHITE GREY CASUAL SHIRT                            ","MEN'S SKY BLUE CASUAL SHIRT                              ","MEN'S BLUE CASUAL SHIRT                                  ","MEN'S LIGHT GREEN SHIRT                                  ","MEN'S BLUE WHITE CASUAL SHIRT                            ","MEN'S BROWN CASUAL SHIRT                                 ","MEN'S BLACK GREY CASUAL SHIRT                            ","MEN'S GREY CASUAL SHIRT                                  ","MEN'S WHITE CASUAL SHIRT                                 ","MEN'S GREEN CASUAL SHIRT                                 ","MEN'S BROWN GREY SHIRT                                   ","MEN'S BLUE CASUAL SHIRT                                  ","MEN'S WHITE CASUAL SHIRT                                 ","MEN'S GREEN/BLACK CASUAL SHIRT                           ","MEN'S DARK NAVY CASUAL SHIRT                             "};
	//CASUAL SHIRTS;
	int men_top_casual_shirts_price[15]={2790,2991,2790,2790,2790,3691,2991,2790,2991,2991,3291,2591,2790,3291,2991};	//PRICE CASUAL SHIRTS;
	int men_top_casual_shirts_code[15];
	
	char men_top_polo_tshirts[15][100]={"MEN'S GREEN BLUE POLO SHIRT                             ","MEN'S BLACK POLO SHIRT                                  ","MEN'S ORANGE POLO SHIRT                                 ","MEN'S'DARK BLUE POLO SHIRT                              ","MEN'S CORAL POLO SHIRT                                  ","MEN'S EMINENT BLUE POLO SHIRT                           ","MEN'S BROWN POLO SHIRT                                  ","MEN'S FUNKY BLACK POLO SHIRT                            ","MEN'S YELLOW//BLACK POLO                                ","MEN'S BLACK/MAROON POLO                                 ","MEN'S WHITE POLO SHIRT                                  ","MEN'S POLO GREEN/NAVY BLUE                              ","MEN'S POLO BOND BLUE                                    ","MEN'S POLO RED AND DARK NAVY                            ","MEN'S POLO ROYAL BLUE&GREY                              "};
	//POLO T-SHIRTS
	int men_top_polo_tshirts_price[15]={2991,2691,2490,2290,2490,2991,2490,2790,2991,2991,1591,1591,1691,1891,1991};	//PRICE POLO T-SHIRTS;
	int men_top_polo_tshirts_code[15];
	
	char men_top_graphic_tees[15][100]={"MEN'S BEIGE GRAPHIC TEE                                 ","MEN'S WHITE GRAPHIC TEE                                 ","MEN'S YELLOW GRAPHIC TEE                                ","MEN'S BLACK GRAPHIC TEE                                 ","MEN'S RUST GRAPHIC TEE                                  ","MEN'S RED GRAPHIC TEE                                   ","MEN'S BLACK GRAPHIC TEE                                 ","MEN'S NAVY BLUE GRAPHIC TEE                             ","MEN'S PINK GRAPHIC TEE                                  ","MEN'S TURQUOISE GRAPHIC TEE                             ","MEN'S YELLOW GRAPHIC TEE                                ","MEN'S ORANGE GRAPHIC TEE                                ","MEN'S PURPLE GRAPHIC TEE                                ","MEN'S WHITE/GREEN TEE                                   ","MEN'S NAVY CLASSIC TEE	                                 "};
	//GRAPHIC TEES
	int men_top_graphic_tees_price[15]={1991,1991,1991,1991,1790,1790,2940,1991,1490,2490,1591,1591,1790,1991,2490}; //GRAPHIC TEES PRICE
	int men_top_graphic_tees_code[15];
	
	char men_top_tank_tops[15][100]={"MEN'S WHITE TANK TOP                                    ","MEN'S BLACK TANK TOP                                    ","MEN'S DARK BROWN TANK TOP                               ","MEN'S NAVY TANK TOP                                     ","MEN'S LIME TANK TOP                                     ","MEN'S PEACH TANK TOP                                    ","MEN'S MAROON TANK TOP                                   ","MEN'S SEA GREEN TANK TOP                                ","MEN'S RED TANK TOP	                                     ","MEN'S EMERALD GREEN TANK TOP                            ","MEN'S LIGHT OLIVE TANK TOP                              ","MEN'S OFF WHITE TANK TOP                                ","MEN'S CAMO TANK TOP                                     ","MEN'S OATMEAL TANK TOP                                  ","MEN'S PLUM TANK TOP                                     "};
	//TANK TOPS
	int men_top_tank_top_price[15]={1291,1790,1291,1790,1291,1790,1291,1291,1291,1790,1790,1790,1790,1291,1790};	//PRICE TANK TOP;
	int men_top_tank_top_code[15];
	
	char men_top_basic_tees[15][100]={"MEN'S BLACK BASIC TEE	                                 ","MEN'S PURPLE BASIC TEE                                  ","MEN'S MAROON BASIC TEE                                  ","MEN'S HEATHER GREY BASIC TEE                            ","MEN'S PURPLE BASIC TEE                                  ","MEN'S ARMY GREEN BASIC TEE                              ","MEN'S CHARCOAL BASIC TEE                                ","MEN'S NAVY BASIC TEE	                                 ","MEN'S HEATHER GREY BASIC TEE                            ","MEN'S WHITE BASIC TEE                                   ","MEN'S YELLOW BASIC TEE                                  ","MEN'S BLUE BASIC TEE	                                 ","MEN'S RED BASIC TEE	                                 ","MEN'S BROWN BASIC TEE                                   ","MEN'S LIGHT GREEN BASIC TEE                             "};
	//BASIC TEES;
	int men_top_basic_tees_price[15]={1290,1290,1290,1490,1290,1590,1590,1490,1290,1290,1690,1690,1690,1490,1490};	//PRICE BASIC TEES;
	int men_top_basic_tees_code[15];
	
	char men_top_kurta_shalwar[15][100]={"PLUM BLENDED KAMEEZ SHALWAR	                         ","TEAL BLENDED KAMEEZ SHALWAR	                         ","STONE BLUE BLENDED KAMEEZ SHALWAR                       ","CHARCOAL GREY BLENDED KAMEEZ SHALWAR                    ","MAROON BLENDED KURTA PAJAMA	                         ","NAVY BLUE COTTON KAMEEZ SHALWAR                         ","DARK PURPLE COTTON KURTA PAJAMA                         ","SAND BLENDED KAMEEZ SHALWAR	                         ","NAVY BLUE BLENDED KURTA PAJAMA                          ","WHITE BLENDED KAMEEZ SHALWAR	                         ","DARK GREY COTTON KAMEEZ SHALWAR                         ","BLACK COTTON KAMEEZ SHALWAR	                         ","DARK GREY BLENDED KAMEEZ SHALWAR                        ","BROWN TEXTURE CVC KURTA PAJAMA                          ","DENIM BLUE COTTON KAMEEZ SHALWAR                        "};
	//KURTA SHALWAR;
	int men_top_kurta_shalwar_price[15]={5890,5990,5490,6290,7990,6990,8390,7390,7990,4590,8990,7790,6990,5290,6990};	//PRICE KURTA SHALWAR;
	int men_top_kurta_shalwar_code[15];
	
	// INFORMATION OF MEN'S BOTTOMS:
	char men_bottom_jogger_pants[15][100]={"MEN'S CAMEL JOGGER PANT                                 ","MEN'S RUST JOGGER PANT                                  ","MEN'S PURPLE JOGGER PANT                                ","MEN'S RED JOGGER PANT                                   ","MEN'S ORANGE JOGGER PANT                                ","MEN'S BLACK JOGGER PANT                                 ","MEN'S WHITE JOGGER PANT                                 ","MEN'S MAROON JOGGER PANT                                ","MEN'S GREY JOGGER PANT                                  ","MEN'S BROWN JOGGER PANT                                 ","MEN'S WHITE JOGGER PANT                                 ","MEN'S DARK BLUE JOGGER PANT                             ","MENS LIGHT BLUE JOGGER PANT                             ","MEN'S DARK GREEN JOGGER PANT                            ","MEN'S COFFEE BROWN JOGGER PANT                          "};
	//JOGGER PANTS
	int men_bottom_jogger_pants_price[15]={1646,1646,1095,1095,1096,1646,2050,2050,2050,1645,1750,1750,1550,1550,2050};		//JOGGER PANTS PRICE;
	int men_bottom_jogger_pants_code[15];
	
	char men_bottom_denim_pants[15][100]={"MEN'S INDIGO DENIM PANT                                 ","MEN'S DARK BLUE DENIM PANT                              ","MEN'S BLUE DENIM PANT                                   ","MEN'S WASHED BLUE DENIM PANT                            ","MEN'S MOUNTAIN BLUE DENIM PANT                          ","MEN'S DIRTY BLUE DENIM PANT                             ","MEN'S WASHED INDIGO DENIM PANT                          ","MEN'S MID INDIGO DENIM PANT                             ","MEN'S BLACK DENIM PANT                                  ","MEN'S MID TEAL DENIM PANT                               ","MEN'S LIGHT BLUE DENIM PANT                             ","MEN'S GREY KNITTED JEANS                                ","MEN'S CHARCOAL KNITTED JEANS                            ","MEN'S LIGHT BLUE KNITTED JEANS                          ","MEN'S DARK BROWN JEANS                                  "};
	//MEN'S DENIM PANTS;
	int men_bottom_denim_pants_price[15]={4491,4491,4491,4491,4491,4491,4491,4491,4491,4491,4491,3350,3350,3350,3350};	//MEN'S DENIM PANTS PRICE;
	int men_bottom_denim_pants_code[15];
	
	char men_bottom_chino_pants[15][100]={"MEN'S BLACK CHINO PANT                                  ","MEN'S ANTHRACITE CHINO PANT                             ","MEN'S GREY CHINO PANT                                   ","MEN'S KHAKI CHINO PANT                                  ","MEN'S NAVY CHINO PANT                                   ","MEN'S BLACK CHINO PANT                                  ","MEN'S DARK BROWN CHINO PANT                             ","MEN'S CARAMEL CHINO PANT                                ","MEN'S BURGUNDY CHINO PANT                               ","MEN'S WHITE CHINO PANT                                  ","MEN'S MAROON CHINO PANT                                 ","MEN'S BLUE CHINO PANT                                   ","MEN'S COFFEE BROWN CHINO PANT                           ","MEN'S CHARCOAL CHINO PANT                               ","MEN'S ICE BLUE CHINO PANT                               "};
	//CHINO PANTS;
	int men_bottom_chino_pants_price[15]={4491,4491,4491,4491,4491,4491,4491,3190,2991,2991,3190,2991,3190,3190,2991};	//CHINO PANTS PRICE;
	int men_bottom_chino_pants_code[15];
	
	char men_bottom_shorts[15][100]={"MEN'S BLACK SHORTS                                      ","MEN'S CAMEL SHORTS                                      ","MEN'S BROWN SHORT                                       ","MEN'S BLUE NAVY SHORTS                                  ","MEN'S WHITE SHORTS                                      ","MEN'S BLACK WHITE SHORTS                                ","MEN'S GREEN YELLOW SHORTS                               ","MEN'S BLUE WHITE SHORTS                                 ","MEN'S GREEN SHORTS                                      ","MEN'S RED SHORTS                                        ","MEN'S CAMO SHORTS                                       ","MEN'S SKY SHORTS                                        ","MEN'S GREY SHORTS                                       ","MEN'S COFFEE BROWN SHORTS                               ","MEN'S ICE BLUE SHORTS                                   "};
	//SHORTS;
	int men_bottom_shorts_price[15]={2991,2991,2991,2390,2390,2390,2390,2991,1991,1991,1991,1991,2991,2991,2390}; //SHORTS PRICE;
	int men_bottom_shorts_code[15];
	
	//INFORMATION OF WOMEN'S CLOTHING:
	//INFORMATION OF WOMEN'S TOP:
	char women_top_threepiece_suits[15][100]={"GREEN YARN DYED COTTON BROSHIA JACQUARD                 ","GREYISH YARN DYED COTTON POLY BROSHA JACQUARD           ","MAROON YARN DYED SLUB KHADDAR JACQUARD                  ","RED AND GREEN DYED EMBROIDERED CROSSHATCH               ","PRINTED MARINA HERRINGBONE                              ","PRINTED LIGHT BLUE KHADDAR                              ","PRINTED BLACK LAWN                                      ","PRINTED RED KARANDI                                     ","PRINTED DARK BLUE CAMBRIC                               ","PRINTED LIGHT GREENPOLYESTER VISCOSE                    ","PRINTED BLACK KARANDI                                   ","BLACK AND BLUE DYED EMBROIDERED CROSSHATCH              ","BLUE AND GREEN DYED EMBROIDERED CROSSHATCH              ","RED YARN DYED COTTON BROSHIA JACQUARD                   ","PRINTED SEA GREEN HERRINGBONE                           "};
	//THREE PIECE SUITS;
	int women_top_threepiece_suits_price[15]={4491,4491,4491,4491,4491,4491,4491,4491,4491,4491,4491,3350,3350,3350,3350}; //THREE PIECE SUITS PRICE;
	int women_top_threepiece_suits_code[15];
	
	char women_top_western_dress[15][100]={"ROUND NECK BLACK DYED LYCRA TERRY MAXI DRESS            ","ROUND NECK RED DYED LYCRA TERRY MAXI DRESS              ","ROUND NECK DARK BLUE DYED LYCRA TERRY MAXI DRESS        ","A-LINE MAROOM DYED LYCRA RIB MAXI DRESS                 ","A-LINE BROWN DYED LYCRA RIB MAXI DRESS                  ","A-LINE LIGHT BLUE DYED LYCRA RIB MAXI DRESS             ","DROP SHOULDER GREEN PRINTED LYCRA TERRY MAXI DRESS      ","DROP SHOULDER PURPLE PRINTED LYCRA TERRY MAXI DRESS     ","DROP SHOULDER ORANGE PRINTED LYCRA TERRY MAXI DRESS     ","V NECK WHITE PRINTED LYCRA TERRY MAXI DRESS             ","V NECK PRINTED LYCRA TERRY MAXI DRESS                   ","TIERED SEA BLUE DYED POLYESTER VISCOSE JERSEY           ","TIERED SEA GREEN DYED POLYESTER VISCOSE JERSEY          ","YARN DYED EMBROIDERED PINK MAXI DRESS                   ","YARN DYED EMBROIDERED MUSTARD MAXI DRESS                "};
	//WESTERN DRESS;	
	int	women_top_western_dress_price[15]={5800,5800,5800,5500,5500,5500,6150,6150,6150,4900,4900,4900,4900,5150,5150}; //WESTERN DRESS PRICE;
	int women_top_western_dress_code[15];
	
	char women_top_jackets[15][100]={"NAVY MOCK NECK PARACHUTE JACKET                         ","PINK CROPPED JACKET                                     ","DENIM JACKET WITH CONTRAST PATTERN                      ","SKIN HOODED PUFFER PARACHUTE JACKET                     ","BLACK EMBROIDERED CROPPED JACKET                        ","MAROON LEATHER JACKET                                   ","OLIVE PUFFER PARKA JACKET                               ","MAROON MOCK NECK PARACHUTE JACKET                       ","RED FLORAL JACQUARD JACKET                              ","MAROON SHERPA COLLAR SUEDE JACKET                       ","BLACK FLORAL VELVET JACKET                              ","FLORAL JACQUARD JACKET WITH STRIPES                     ","BLACK PUFFER JACKET                                     ","MULTI COLOR PRINTED JACQUARD JACKET                     ","BLACK HOODED PARACHUTE JACKET                           "};
	//JACKETS;
	int women_top_jackets_price[15]={8999,8999,4999,8999,5499,6999,12999,8999,5999,9499,5499,5999,9999,4999,8999}; //JACKETS PRICE;
	int women_top_jackets_code[15];
	 
			
	//INFORMATION OF WOMEN'S BOTTOM CLOTHING:
	char women_bottom_denim_pants[15][100]={"MEN'S INDIGO DENIM PANT                                 ","MEN'S DARK BLUE DENIM PANT                              ","MEN'S BLUE DENIM PANT                                   ","MEN'S WASHED BLUE DENIM PANT                            ","MEN'S MOUNTAIN BLUE DENIM PANT                          ","MEN'S DIRTY BLUE DENIM PANT                             ","MEN'S WASHED INDIGO DENIM PANT                          ","MEN'S MID INDIGO DENIM PANT                             ","MEN'S BLACK DENIM PANT                                  ","MEN'S MID TEAL DENIM PANT                               ","MEN'S LIGHT BLUE DENIM PANT                             ","MEN'S GREY KNITTED JEANS                                ","MEN'S CHARCOAL KNITTED JEANS                            ","MEN'S LIGHT BLUE KNITTED JEANS                          ","MEN'S DARK BROWN JEANS                                  "};
	//WOMEN'S DENIM PANTS;
	int	women_bottom_denim_pants_price[15]={4491,4491,4491,4491,4491,4491,4491,4491,4491,4491,4491,3350,3350,3350,3350};	//WOMEN'S DENIM PANTS PRICE;
	int women_bottom_denim_pants_code[15];
	char women_bottom_skirts[15][100]={"ECRU FLARED MESH SKIRT                                  ","CHAMBRAY BLUE TIERED SKIRT                              ","BLUSH PINK MESH FLARED SKIRT                            ","YELLOW GEORGETTE TIERED SKIRT                           ","JET BLACK PRINTED PANELLED SKIRT                        ","RED AND ECRU ANARKALI SKIRT                             ","ECRU AND BLUE MIX MATCH SKIRT                           ","MUSTARD YELLOW KALIDAR SKIRT                            ","GOLD PRINTED SKIRT                                      ","PASTEL GREEN PRINT MIX PANELLED SKIRT                   ","BEIGE GLITTER PRINT SKIRT                               ","OFF-WHITE PRINTED SKIRT                                 ","DARK RED SOLID DIVIDED SKIRT                            ","LEAF GREEN GLITTER PRINTED CULOTTES                     ","BLUE JACQUARD SKIRT                                     "};
	//SKIRTS;
	int	women_bottom_skirts_price[15]={2999,2999,2999,2999,3999,3999,3999,4999,4999,5999,5999,5999,2599,2599,2599};  //SKIRTS PRICE
	int women_bottom_skirts_code[15];
	
	char women_bottom_trousers[15][100]={"PINK KNIT TROUSERS                                      ","DARK BLUE KNIT TROUSERS                                 ","BROWN KNIT TROUSERS                                     ","NAVY SWEATPANTS                                         ","CREAM SWEATPANTS                                        ","AQUA EMBROIDERED SWEATPANTS                             ","GREEN LOOSE FIT BASIC JOGGERS                           ","BLACK LOOSE FIT BASIC JOGGERS                           ","CHARCOAL COLORED LOOSE FIT BASIC JOGGERS                ","MAROON SLIM FIT TROUSERS                                ","PURPLE SLIM FIT TROUSERS                                ","WHITE STRAIGHT FIT JERSEY TROUSERS                      ","YELLOW STRAIGHT FIT JERSEY TROUSERS                     ","NON DENIM GREY FLARE TROUSERS                           ","NON DENIM ORANGE FLARE TROUSERS                         "};
	//TROUSERS;
	int women_bottom_trousers_price[15]={3354,3354,3354,2890,2890,2890,3690,3690,3690,2154,2154,2154,2754,2754,2754};	//TROUSERS PRICE;
	int women_bottom_trousers_code[15];
	
	
	
	
	//CREATING CODE FOR KIDS,TEENS AND ADULTS CLOTHING:
	for (i=0; i<15; i++)
	{
		kids_boys_tops_hoodies_and_sweatshirts_codes[i] = (1100 + rand() % 100);
		kids_boys_tops_kurta_and_shalwar_kameez_codes[i] = (1200 + rand() % 100);
		kids_boys_tops_sets_and_suits_codes[i] = (1300 + rand() % 100);
		kids_boys_tops_coats_and_jackets_codes[i] = (1400 + rand() % 1100);
		kids_boys_tops_printed_tees_codes[i] = (1500 + rand() % 100);
		
		kids_boys_bottoms_jeans_codes[i] = (1600 + rand() % 100);
		kids_boys_bottoms_shorts_codes[i] = (1700 + rand() % 100);
		kids_boys_bottoms_pyjamas_and_trousers_codes[i] = (1800 + rand() % 100);
		
		kids_girls_tops_jackets_and_sweatshirts_codes[i] = (1900 + rand() % 100);
		kids_girls_tops_sets_and_suits_codes[i] = (2000 + rand() % 100);
		kids_girls_tops_frocks_codes[i] = (2100 + rand() % 100);
		
		kids_girls_bottoms_pants_and_leggings_codes[i] = (2200 + rand() % 100);
		kids_girls_bottoms_socks_and_tights_codes[i] = (2300 + rand() % 100);
		kids_girls_bottoms_shorts_and_skirts_codes[i] = (2400 + rand() % 100);
		
		teen_boys_top_shirts_tshirts_code[i]=(3300+ rand() % 100);
		teen_boys_tops_hoodies_sweatshirts_code[i]=(3100+ rand() % 100);
		teen_boys_tops_kurta_shalwar_code[i]=(3200+ rand() % 100); //CODE FOR TEEN BOYS TOP
		
		teen_boys_bottom_dress_pants_code[i]=(3300+ rand() % 100);
		teen_boys_bottom_jeans_code[i]=(3400+ rand() % 100);
		teen_boys_bottom_shorts_code[i]=(3500+ rand() % 100);
		
		teen_girls_top_kurtis_code[i]=(3600+ rand() % 100);
		teen_girls_top_tees_code[i]=(3700+ rand() % 100);
		teen_girls_top_hoodies_sweatshirts_code[i]=(3800+ rand() % 100);	//CODE FOR TEEN GIRLS TOP
		
		teen_girls_bottom_jeans_code[i]=(3900+ rand() % 100);
		teen_girls_bottom_shalwar_code[i]=(4000+ rand() % 100);
		teen_girls_bottom_trousers_code[i]=(4100+ rand() % 100);	//CODE FOR TEEN GIRLS BOTTOM
		
		men_top_casual_shirts_code[i]=(5000 + rand() % 100);
		men_top_polo_tshirts_code[i]=(5100 + rand() % 100);
		men_top_graphic_tees_code[i]=(5200 + rand() % 100);
		men_top_tank_top_code[i]=(5300 + rand() % 100);
		men_top_basic_tees_code[i]=(5400 + rand() % 100);
		men_top_kurta_shalwar_code[i]=(5500 + rand() % 100);	//CODE FOR MEN'S TOPS.
		
		men_bottom_jogger_pants_code[i]=(5600 +rand() % 100);
		men_bottom_denim_pants_code[i]=(5700 +rand() % 100);
		men_bottom_chino_pants_code[i]=(5800 +rand() % 100);
		men_bottom_shorts_code[i]=(5900 +rand() % 100);		//CODE FOR MEN'S BOTTOM
		
		women_top_threepiece_suits_code[i]=(6000+ rand() % 100);
		women_top_western_dress_code[i]=(6100+ rand() % 100);
		women_top_jackets_code[i]=(6200+ rand() % 100);	//CODE FOR WOMEN'S TOP
		
		women_bottom_denim_pants_code[i]=(6300+ rand() % 100);
		women_bottom_skirts_code[i]=(6400+ rand() % 100);
		women_bottom_trousers_code[i]=(6500+ rand() % 100);	//CODE FOR WOMEN'S BOTTOM
	}
	
	int item_menu_choice, category_choice, item_number;
	char size, category_continue = 'Y', gender, item_choice, sub_category_choice = 'Y';

	if ( main_call == 0 )
	{
		printf("22K-4132 \t Muhammad Aliyan Malik \n22K-4275 \t Umair Ahsan \n22K-4140 \t Syed Azhaan Ali");
		printf("\n\n\n\t\t  * * * * * * *\n\t\t  *   *  *    *\n\t\t  *  ******   *   - - - - - - - - - - - - - -\n\t\t  * * * * * * *                             |\n\t\t      ****                                  |\n\t      * * * * * * * * * * *  \t                    |\n\t* * * *                   * * * *          * * * * * * * * * *\n\t* * * *  * * * * * * * *  * * * *          *    WELCOME TO   *\n\t* *   *  *SHOP-IN STORE*  *   * *          *  SHOP-IN STORE  *\n\t* *   *  *   CHATBOT   *  *   * *          * * * * * * * * * *\n\t* *   *  * * * * * * * *  *   * *\n\t***   *                   *   ***                   Shop from exclusive range of new arrivals and latest\n\t      * * * * * * * * * * *                       trends clothing for kids, teens, men and women in Pakistan.\n\t        *  *        *  *         \n\t        *  *        *  *                                  We offer discount for following ranges:\n\t        *  *        *  *                                        9,999+   -  10%% discount\n\t        *  *        *  *                                        19,999+  -  20%% discount\n\t        ****        ****                                        29,999+  -  40%% discount\n" );
		//intro
	}
	
	

		do
		{
		printf("\n\n\nno.   CATEGORY \t\t AGE \n---   -------- \t\t --- \n1.    Kids \t\t 4 - 12 \n2.    Teens \t\t 13 - 19 \n3.    Adults \t\t Above 19\n\nEnter serial number of the category you wish to select: ");
		scanf(" %d", &category_choice);
		
		
		if ( (category_choice == 1) || (category_choice == 2) || (category_choice == 3) )
			break;
		else
			printf("\nINVALID INPUT!\n");
		}
		while ( 1 );
		
		switch (category_choice)
		{
			case 1:	while ( sub_category_choice == 'Y' )
					{
					do
					{
					printf("\nSelect Gender. Enter 'M' for Male and 'F' for Female: ");
					scanf(" %c", &gender);
					if ( gender == 'm' )
						gender = 'M';
					if ( gender == 'f' )
						gender = 'F';
					if ( (gender == 'M') || (gender == 'F') )
						break;
					else
					{
						printf("\nINVALID INPUT!\n");
						continue;
					}
					}
					while (1);
						
					switch (gender)
					{
						case 'M':	do
									{
									printf("\nno.   CATEGORY\n---   --------\n1.    Hoodies and Sweatshirts\n2.    Kurta and Shalwar Kameez\n3.    Sets and Suits\n4.    Coats and Jackets\n5.    Printed Tees\n6.    Jeans\n7.    Shorts\n8.    Pyjamas and Trousers\n\nEnter serial number of the category you wish to select: ");
									scanf("%d", &item_menu_choice);
									if ( (item_menu_choice >= 1) && (item_menu_choice <= 8) )
										break;
									else
									{
										printf("\nINVALID INPUT!\n");
										continue;
									}
									}
									while (1);
									switch (item_menu_choice)
									{
										case 1:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, kids_boys_tops_hoodies_and_sweatshirts[i], kids_boys_tops_hoodies_and_sweatshirts_prices[i], kids_boys_tops_hoodies_and_sweatshirts_codes[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'S' for Small and 'M' for Medium): ");
													scanf(" %c", &size);
													if ( size == 's' )
														size = 'S';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'S') || (size == 'M') )
													{
													item_bought( &kids_boys_tops_hoodies_and_sweatshirts[item_number-2][100], &kids_boys_tops_hoodies_and_sweatshirts_prices[item_number-1] , &kids_boys_tops_hoodies_and_sweatshirts_codes[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
														
												}
												break;
												
										case 2:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, kids_boys_tops_kurta_and_shalwar_kameez[i], kids_boys_tops_kurta_and_shalwar_kameez_prices[i], kids_boys_tops_kurta_and_shalwar_kameez_codes[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													printf("\nEnter size (Enter 'S' for Small and 'M' for Medium): ");
													scanf(" %c", &size);
													if ( size == 's' )
														size = 'S';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'S') || (size == 'M') )
													{
													item_bought( &kids_boys_tops_kurta_and_shalwar_kameez[item_number-2][100], &kids_boys_tops_kurta_and_shalwar_kameez_prices[item_number-1] , &kids_boys_tops_kurta_and_shalwar_kameez_codes[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												
												break;
												
										case 3:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, kids_boys_tops_sets_and_suits[i], kids_boys_tops_sets_and_suits_prices[i], kids_boys_tops_sets_and_suits_codes[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select, Enter any other key to continue: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													printf("\nEnter size (Enter 'S' for Small and 'M' for Medium): ");
													scanf(" %c", &size);
													if ( size == 's' )
														size = 'S';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'S') || (size == 'M') )
													{
													item_bought( &kids_boys_tops_sets_and_suits[item_number-2][100], &kids_boys_tops_sets_and_suits_prices[item_number-1] , &kids_boys_tops_sets_and_suits_codes[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;	
													}
												}
												
												break;
												
										case 4:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, kids_boys_tops_coats_and_jackets[i], kids_boys_tops_coats_and_jackets_prices[i], kids_boys_tops_coats_and_jackets_codes[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													printf("\nEnter size (Enter 'S' for Small and 'M' for Medium): ");
													scanf(" %c", &size);
													if ( size == 's' )
														size = 'S';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'S') || (size == 'M') )
													{
													item_bought( &kids_boys_tops_coats_and_jackets[item_number-2][100], &kids_boys_tops_coats_and_jackets_prices[item_number-1] , &kids_boys_tops_coats_and_jackets_codes[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;	
													}
												}
												
												break;
												
										case 5:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, kids_boys_tops_printed_tees[i], kids_boys_tops_printed_tees_prices[i], kids_boys_tops_printed_tees_codes[i]);
												}
												item_choice = 'Y';
												while ( item_choice == 'Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													printf("\nEnter size (Enter 'S' for Small and 'M' for Medium): ");
													scanf(" %c", &size);
													if ( size == 's' )
														size = 'S';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'S') || (size == 'M') )
													{
													item_bought( &kids_boys_tops_printed_tees[item_number-2][100], &kids_boys_tops_printed_tees_prices[item_number-1] , &kids_boys_tops_printed_tees_codes[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												
												break;
										
										
										case 6:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, kids_boys_bottoms_jeans[i], kids_boys_bottoms_jeans_prices[i], kids_boys_bottoms_jeans_codes[i]);
												}
												item_choice = 'Y';
												while ( item_choice == 'Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													printf("\nEnter size (Enter 'S' for Small and 'M' for Medium): ");
													scanf(" %c", &size);
													if ( size == 's' )
														size = 'S';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'S') || (size == 'M') )
													{
													item_bought( &kids_boys_bottoms_jeans[item_number-2][100], &kids_boys_bottoms_jeans_prices[item_number-1] , &kids_boys_bottoms_jeans_codes[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												
												break;
										
										
										case 7:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, kids_boys_bottoms_shorts[i], kids_boys_bottoms_shorts_prices[i], kids_boys_bottoms_shorts_codes[i]);
												}
												item_choice = 'Y';
												while ( item_choice == 'Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													printf("\nEnter size (Enter 'S' for Small and 'M' for Medium): ");
													scanf(" %c", &size);
													if ( size == 's' )
														size = 'S';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'S') || (size == 'M') )
													{
													item_bought( &kids_boys_bottoms_shorts[item_number-2][100], &kids_boys_bottoms_shorts_prices[item_number-1] , &kids_boys_bottoms_shorts_codes[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												
												break;
										
										case 8:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, kids_boys_bottoms_pyjamas_and_trousers[i], kids_boys_bottoms_pyjamas_and_trousers_prices[i], kids_boys_bottoms_pyjamas_and_trousers_codes[i]);
												}
												item_choice = 'Y';
												while ( item_choice == 'Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													printf("\nEnter size (Enter 'S' for Small and 'M' for Medium): ");
													scanf(" %c", &size);
													if ( size == 's' )
														size = 'S';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'S') || (size == 'M') )
													{
													item_bought( &kids_boys_bottoms_pyjamas_and_trousers[item_number-2][100], &kids_boys_bottoms_pyjamas_and_trousers_prices[item_number-1] , &kids_boys_bottoms_pyjamas_and_trousers_codes[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												
												break;
										
										default:	printf("\nInavlid input!");
													break;
									}
									break;
								
									
						case 'F':	do
									{
									printf("\nno.   CATEGORY\n---   --------\n1.    Jackets and Sweatshirts\n2.    Sets and Suits\n3.    Frocks\n4.    Pants and Leggings\n5.    Socks and Tights\n6.    Shorts and Skirts\n\nEnter serial number of the category you wish to select: ");
									scanf("%d", &item_menu_choice);
									if ( (item_menu_choice >= 1) && (item_menu_choice <= 6) )
										break;
									else
									{
										printf("\nINVALID INPUT!\n");
										continue;
									}
									}
									while (1);
									switch (item_menu_choice)
									{
										case 1:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, kids_girls_tops_jackets_and_sweatshirts[i], kids_girls_tops_jackets_and_sweatshirts_prices[i], kids_girls_tops_jackets_and_sweatshirts_codes[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'S' for Small and 'M' for Medium): ");
													scanf(" %c", &size);
													if ( size == 's' )
														size = 'S';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'S') || (size == 'M') )
													{
													item_bought( &kids_girls_tops_jackets_and_sweatshirts[item_number-2][100], &kids_girls_tops_jackets_and_sweatshirts_prices[item_number-1] , &kids_girls_tops_jackets_and_sweatshirts_codes[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
														
												}
												break;
												
										case 2:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, kids_girls_tops_sets_and_suits[i], kids_girls_tops_sets_and_suits_prices[i], kids_girls_tops_sets_and_suits_codes[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													printf("\nEnter size (Enter 'S' for Small and 'M' for Medium): ");
													scanf(" %c", &size);
													if ( size == 's' )
														size = 'S';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'S') || (size == 'M') )
													{
													item_bought( &kids_girls_tops_sets_and_suits[item_number-2][100], &kids_girls_tops_sets_and_suits_prices[item_number-1] , &kids_girls_tops_sets_and_suits_codes[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												
												break;
												
										case 3:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, kids_girls_tops_frocks[i], kids_girls_tops_frocks_prices[i], kids_girls_tops_frocks_codes[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select, Enter any other key to continue: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													printf("\nEnter size (Enter 'S' for Small and 'M' for Medium): ");
													scanf(" %c", &size);
													if ( size == 's' )
														size = 'S';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'S') || (size == 'M') )
													{
													item_bought( &kids_girls_tops_frocks[item_number-2][100], &kids_girls_tops_frocks_prices[item_number-1] , &kids_girls_tops_frocks_codes[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;	
													}
												}
												
												break;
												
										case 4:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, kids_girls_bottoms_pants_and_leggings[i], kids_girls_bottoms_pants_and_leggings_prices[i], kids_girls_bottoms_pants_and_leggings_codes[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													printf("\nEnter size (Enter 'S' for Small and 'M' for Medium): ");
													scanf(" %c", &size);
													if ( size == 's' )
														size = 'S';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'S') || (size == 'M') )
													{
													item_bought( &kids_girls_bottoms_pants_and_leggings[item_number-2][100], &kids_girls_bottoms_pants_and_leggings_prices[item_number-1] , &kids_girls_bottoms_pants_and_leggings_codes[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;	
													}
												}
												
												break;
												
										case 5:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, kids_girls_bottoms_socks_and_tights[i], kids_girls_bottoms_socks_and_tights_prices[i], kids_girls_bottoms_socks_and_tights_codes[i]);
												}
												item_choice = 'Y';
												while ( item_choice == 'Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													printf("\nEnter size (Enter 'S' for Small and 'M' for Medium): ");
													scanf(" %c", &size);
													if ( size == 's' )
														size = 'S';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'S') || (size == 'M') )
													{
													item_bought( &kids_girls_bottoms_socks_and_tights[item_number-2][100], &kids_girls_bottoms_socks_and_tights_prices[item_number-1] , &kids_girls_bottoms_socks_and_tights_codes[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												
												break;
										
										
										case 6:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, kids_girls_bottoms_shorts_and_skirts[i], kids_girls_bottoms_shorts_and_skirts_prices[i], kids_girls_bottoms_shorts_and_skirts_codes[i]);
												}
												item_choice = 'Y';
												while ( item_choice == 'Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													printf("\nEnter size (Enter 'S' for Small and 'M' for Medium): ");
													scanf(" %c", &size);
													if ( size == 's' )
														size = 'S';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'S') || (size == 'M') )
													{
													item_bought( &kids_girls_bottoms_shorts_and_skirts[item_number-2][100], &kids_girls_bottoms_shorts_and_skirts_prices[item_number-1] , &kids_girls_bottoms_shorts_and_skirts_codes[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												
												break;
										
										
										default:	printf("\nInavlid input!");
													break;
									}
									break;
									
									
									break;
									
						default:	printf("\nInavlid input!");
									break;
					}
					printf("\nEnter 'Y' to continue in Kids section, Enter any other key to continue: ");
					scanf(" %c", &sub_category_choice);
					if ( sub_category_choice == 'y' )
						sub_category_choice = 'Y';
					}
					
					break;
			
			case 2:	sub_category_choice = 'Y';
					while ( sub_category_choice == 'Y' )
					{
					do
					{
					printf("\nSelect Gender. Enter 'M' for Male and 'F' for Female: ");
					scanf(" %c", &gender);
					if ( gender == 'm' )
						gender = 'M';
					if ( gender == 'f' )
						gender = 'F';
					if ( (gender == 'M') || (gender == 'F') )
						break;
					else
					{
						printf("\nINVALID INPUT!\n");
						continue;
					}
					}
					while (1);
					switch (gender)
					{
						case 'M':	
									do
									{
										printf("\nno.   CATEGORY\n---   --------\n1.    Shirts & T-Shirts\n2.    Hoodies & Sweat Shirts\n3.    Kurta Shalwar\n4.    Dress Pants\n5.    Jeans\n6.    Shorts\n\nEnter serial number of the category you wish to select: ");
										scanf("%d", &item_menu_choice);
									if ( (item_menu_choice >= 1) && (item_menu_choice <= 6) )
										break;
									else
									{
										printf("\nINVALID INPUT!\n");
										continue;
									}
									}
									while (1);	
									switch (item_menu_choice)
									{
										case 1:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, teen_boys_top_shirts_tshirts[i], teen_boys_top_shirts_tshirts_price[i], teen_boys_top_shirts_tshirts_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'M' for Medium and 'L' for Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'L') || (size == 'M') )
													{
													item_bought( &teen_boys_top_shirts_tshirts[item_number-2][100], &teen_boys_top_shirts_tshirts_price[item_number-1] , &teen_boys_top_shirts_tshirts_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
											break;
										case 2:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, teen_boys_tops_hoodies_sweatshirts[i], teen_boys_tops_hoodies_sweatshirts_price[i], teen_boys_tops_hoodies_sweatshirts_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'M' for Medium and 'L' for Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'L') || (size == 'M') )
													{
													item_bought( &teen_boys_tops_hoodies_sweatshirts[item_number-2][100], &teen_boys_tops_hoodies_sweatshirts_price[item_number-1] , &teen_boys_tops_hoodies_sweatshirts_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
											break;
										case 3:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, teen_boys_tops_kurta_shalwar[i], teen_boys_tops_kurta_shalwar_price[i], teen_boys_tops_kurta_shalwar_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'M' for Medium and 'L' for Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'L') || (size == 'M') )
													{
													item_bought( &teen_boys_tops_kurta_shalwar[item_number-2][100], &teen_boys_tops_kurta_shalwar_price[item_number-1] , &teen_boys_tops_kurta_shalwar_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
											break;
										case 4:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, teen_boys_bottom_dress_pants[i], teen_boys_bottom_dress_pants_price[i], teen_boys_bottom_dress_pants_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'M' for Medium and 'L' for Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'L') || (size == 'M') )
													{
													item_bought( &teen_boys_bottom_dress_pants[item_number-2][100], &teen_boys_bottom_dress_pants_price[item_number-1] , &teen_boys_bottom_dress_pants_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
											break;
										case 5:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, teen_boys_bottom_jeans[i], teen_boys_bottom_jeans_price[i], teen_boys_bottom_jeans_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'M' for Medium and 'L' for Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'L') || (size == 'M') )
													{
													item_bought( &teen_boys_bottom_jeans[item_number-2][100], &teen_boys_bottom_jeans_price[item_number-1] , &teen_boys_bottom_jeans_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
											break;
										case 6:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, teen_boys_bottom_shorts[i], teen_boys_bottom_shorts_price[i], teen_boys_bottom_shorts_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'M' for Medium and 'L' for Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'L') || (size == 'M') )
													{
													item_bought( &teen_boys_bottom_shorts[item_number-2][100], &teen_boys_bottom_shorts_price[item_number-1] , &teen_boys_bottom_shorts_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
											break;
									}
													
									
									break;	//CASE 'M' FOR TEENS END HERE.
									
									break;
									
						case 'F':	
									do
									{
										printf("\nno.   CATEGORY\n---   --------\n1.    Kurtis\n2.    Tees\n3.    Hoodies & Sweat Shirts\n4.    Jeans\n5.    Shalwar\n6.    Trousers\n\nEnter serial number of the category you wish to select: ");
										scanf("%d", &item_menu_choice);
									if ( (item_menu_choice >= 1) && (item_menu_choice <= 6) )
										break;
									else
									{
										printf("\nINVALID INPUT!\n");
										continue;
									}
									}
									while (1);	
									switch (item_menu_choice)
									{
										case 1:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, teen_girls_top_kurtis[i], teen_girls_top_kurtis_price[i], teen_girls_top_kurtis_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'M' for Medium and 'L' for Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'L') || (size == 'M') )
													{
													item_bought( &teen_girls_top_kurtis[item_number-2][100], &teen_girls_top_kurtis_price[item_number-1] , &teen_girls_top_kurtis_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
											break;
										case 2:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, teen_girls_top_tees[i], teen_girls_top_tees_price[i], teen_girls_top_tees_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'M' for Medium and 'L' for Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'L') || (size == 'M') )
													{
													item_bought( &teen_girls_top_tees[item_number-2][100], &teen_girls_top_tees_price[item_number-1] , &teen_girls_top_tees_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
											break;
										case 3:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, teen_girls_top_hoodies_sweatshirts[i], teen_girls_top_hoodies_sweatshirts_price[i], teen_girls_top_hoodies_sweatshirts_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'M' for Medium and 'L' for Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'L') || (size == 'M') )
													{
													item_bought( &teen_girls_top_hoodies_sweatshirts[item_number-2][100], &teen_girls_top_hoodies_sweatshirts_price[item_number-1] , &teen_girls_top_hoodies_sweatshirts_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
											break;
										case 4:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, teen_girls_bottom_jeans[i], teen_girls_bottom_jeans_price[i], teen_girls_bottom_jeans_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'M' for Medium and 'L' for Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'L') || (size == 'M') )
													{
													item_bought( &teen_girls_bottom_jeans[item_number-2][100], &teen_girls_bottom_jeans_price[item_number-1] , &teen_girls_bottom_jeans_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
											break;
										case 5:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, teen_girls_bottom_shalwar[i], teen_girls_bottom_shalwar_price[i], teen_girls_bottom_shalwar_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'M' for Medium and 'L' for Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'L') || (size == 'M') )
													{
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													item_bought( &teen_girls_bottom_shalwar[item_number-2][100], &teen_girls_bottom_shalwar_price[item_number-1] , &teen_girls_bottom_shalwar_code[item_number-1], &size);
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
											break;
										case 6:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, teen_girls_bottom_trousers[i], teen_girls_bottom_trousers_price[i], teen_girls_bottom_trousers_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'M' for Medium and 'L' for Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'm' )
														size = 'M';
													if ( (size == 'L') || (size == 'M') )
													{
													item_bought( &teen_girls_bottom_trousers[item_number-2][100], &teen_girls_bottom_trousers_price[item_number-1] , &teen_girls_bottom_trousers_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
											break;
									}
								
									
									break; //CASE 'F' FOR TEENS GIRLS END HERE 
									
									break;
									
						default:	printf("\nInavlid input!");
									break;
					}
					printf("\nEnter 'Y' to continue in Teens section, Enter any other key to continue: ");
					scanf(" %c", &sub_category_choice);
					if ( sub_category_choice == 'y' )
						sub_category_choice = 'Y';
					}
					
					break;
		
			case 3:	sub_category_choice = 'Y';
					while ( sub_category_choice == 'Y' )
					{
					do
					{
					printf("\nSelect Gender. Enter 'M' for Male and 'F' for Female: ");
					scanf(" %c", &gender);
					if ( gender == 'm' )
						gender = 'M';
					if ( gender == 'f' )
						gender = 'F';
					if ( (gender == 'M') || (gender == 'F') )
						break;
					else
					{
						printf("\nINVALID INPUT!\n");
						continue;
					}
					}
					while (1);
					switch (gender)
					{
						case 'M':	
									do
									{
										printf("\nno.   CATEGORY\n---   --------\n1.    Casual Shirts\n2.    Polo T-Shirts\n3.    Graphic Tees\n4.    Tank Tops\n5.    Basic Tees\n6.    Kurta Shalwar\n7.    Jogger Pants\n8.    Denim Pants\n9.    Chino Pants\n10.   Shorts\n\nEnter serial number of the category you wish to select: ");
										scanf("%d", &item_menu_choice);
									if ( (item_menu_choice >= 1) && (item_menu_choice <= 10) )
										break;
									else
									{
										printf("\nINVALID INPUT!\n");
										continue;
									}
									}
									while (1);	
									switch (item_menu_choice)
									{
										case 1:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, men_top_casual_shirts[i], men_top_casual_shirts_price[i], men_top_casual_shirts_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'L' for Large and 'X' for Extra-Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'x' )
														size = 'X';
													if ( (size == 'L') || (size == 'X') )
													{
													item_bought( &men_top_casual_shirts[item_number-2][100], &men_top_casual_shirts_price[item_number-1] , &men_top_casual_shirts_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												break;	
										case 2:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, men_top_polo_tshirts[i], men_top_polo_tshirts_price[i], men_top_polo_tshirts_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'L' for Large and 'X' for Extra-Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'x' )
														size = 'X';
													if ( (size == 'L') || (size == 'X') )
													{
													item_bought( &men_top_polo_tshirts[item_number-2][100], &men_top_polo_tshirts_price[item_number-1] , &men_top_polo_tshirts_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												break;
										case 3:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, men_top_graphic_tees[i], men_top_graphic_tees_price[i], men_top_graphic_tees_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'L' for Large and 'X' for Extra-Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'x' )
														size = 'X';
													if ( (size == 'L') || (size == 'X') )
													{
													item_bought( &men_top_graphic_tees[item_number-2][100], &men_top_graphic_tees_price[item_number-1] , &men_top_graphic_tees_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												break;	
										case 4:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, men_top_tank_tops[i], men_top_tank_top_price[i], men_top_tank_top_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'L' for Large and 'X' for Extra-Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'x' )
														size = 'X';
													if ( (size == 'L') || (size == 'X') )
													{
													item_bought( &men_top_tank_tops[item_number-2][100], &men_top_tank_top_price[item_number-1] , &men_top_tank_top_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												break;	
										case 5:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, men_top_basic_tees[i], men_top_basic_tees_price[i], men_top_basic_tees_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'L' for Large and 'X' for Extra-Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'x' )
														size = 'X';
													if ( (size == 'L') || (size == 'X') )
													{
													item_bought( &men_top_basic_tees[item_number-2][100], &men_top_basic_tees_price[item_number-1] , &men_top_basic_tees_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												break;
										case 6:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, men_top_kurta_shalwar[i], men_top_kurta_shalwar_price[i], men_top_kurta_shalwar_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'L' for Large and 'X' for Extra-Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'x' )
														size = 'X';
													if ( (size == 'L') || (size == 'X') )
													{
													item_bought( &men_top_kurta_shalwar[item_number-2][100], &men_top_kurta_shalwar_price[item_number-1] , &men_top_kurta_shalwar_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												break;
										case 7:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, men_bottom_jogger_pants[i], men_bottom_jogger_pants_price[i], men_bottom_jogger_pants_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'L' for Large and 'X' for Extra-Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'x' )
														size = 'X';
													if ( (size == 'L') || (size == 'X') )
													{
													item_bought( &men_bottom_jogger_pants[item_number-2][100], &men_bottom_jogger_pants_price[item_number-1] , &men_bottom_jogger_pants_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												break;
										case 8:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, men_bottom_denim_pants[i], men_bottom_denim_pants_price[i], men_bottom_denim_pants_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'L' for Large and 'X' for Extra-Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'x' )
														size = 'X';
													if ( (size == 'L') || (size == 'X') )
													{
													item_bought( &men_bottom_denim_pants[item_number-2][100], &men_bottom_denim_pants_price[item_number-1] , &men_bottom_denim_pants_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												break;
											case 9:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, men_bottom_chino_pants[i], men_bottom_chino_pants_price[i], men_bottom_chino_pants_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'L' for Large and 'X' for Extra-Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'x' )
														size = 'X';
													if ( (size == 'L') || (size == 'X') )
													{
													item_bought( &men_bottom_chino_pants[item_number-2][100], &men_bottom_chino_pants_price[item_number-1] , &men_bottom_chino_pants_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												break;
											case 10:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, men_bottom_shorts[i], men_bottom_shorts_price[i], men_bottom_shorts_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'L' for Large and 'X' for Extra-Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'x' )
														size = 'X';
													if ( (size == 'L') || (size == 'X') )
													{
													item_bought( &men_bottom_shorts[item_number-2][100], &men_bottom_shorts_price[item_number-1] , &men_bottom_shorts_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												break;
												
																				
										}
						break;		//CASE 'M' FOR MEN'S CLOTHING ENDS HERE.
									
									break;
									
						case 'F':	
									do
									{
										printf("\nno.   CATEGORY\n---   --------\n1.    Three Piece Suits\n2.    Western Dress\n3.    Jackets\n4.    Denim Pants\n5.    Jeans\n6.    Trousers\n\nEnter serial number of the category you wish to select: ");
										scanf("%d", &item_menu_choice);
									if ( (item_menu_choice >= 1) && (item_menu_choice <= 6) )
										break;
									else
									{
										printf("\nINVALID INPUT!\n");
										continue;
									}
									}
									while (1);	
									switch (item_menu_choice)
									{
										case 1:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, women_top_threepiece_suits[i], women_top_threepiece_suits_price[i],men_top_casual_shirts_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'L' for Large and 'X' for Extra-Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'x' )
														size = 'X';
													if ( (size == 'L') || (size == 'X') )
													{
													item_bought( &women_top_threepiece_suits[item_number-2][100], &women_top_threepiece_suits_price[item_number-1] ,&women_top_threepiece_suits_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												break;	
										case 2:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, women_top_western_dress[i], women_top_western_dress_price[i], women_top_western_dress_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'L' for Large and 'X' for Extra-Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'x' )
														size = 'X';
													if ( (size == 'L') || (size == 'X') )
													{
													item_bought( &women_top_western_dress[item_number-2][100], &women_top_western_dress_price[item_number-1] , &women_top_western_dress_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												break;
										case 3:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, women_top_jackets[i], women_top_jackets_price[i], women_top_jackets_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'L' for Large and 'X' for Extra-Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'x' )
														size = 'X';
													if ( (size == 'L') || (size == 'X') )
													{
													item_bought( &women_top_jackets[item_number-2][100], &women_top_jackets_price[item_number-1] , &women_top_jackets_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												break;	
										case 4:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, women_bottom_denim_pants[i], women_bottom_denim_pants_price[i], women_bottom_denim_pants_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'L' for Large and 'X' for Extra-Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'x' )
														size = 'X';
													if ( (size == 'L') || (size == 'X') )
													{
													item_bought( &women_bottom_denim_pants[item_number-2][100], &women_bottom_denim_pants_price[item_number-1] , &women_bottom_denim_pants_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												break;	
										case 5:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, women_bottom_skirts[i], women_bottom_skirts_price[i], women_bottom_skirts_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'L' for Large and 'X' for Extra-Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'x' )
														size = 'X';
													if ( (size == 'L') || (size == 'X') )
													{
													item_bought( &women_bottom_skirts[item_number-2][100], &women_bottom_skirts_price[item_number-1] , &women_bottom_skirts_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												break;
										case 6:	printf("\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE\n---\t\t--------- \t\t\t\t\t\t  ----- \t----\n");
												for (i=0; i<15; i++)
												{
													printf("%d.\t%s \t Rs.%d \t%d\n", i+1, women_bottom_trousers[i], women_bottom_trousers_price[i], women_bottom_trousers_code[i]);
												}
												item_choice = 'Y';
												while ( item_choice=='Y' )
												{
													printf("\nEnter serial number of the item you wish to select: ");
													scanf(" %d", &item_number);
													if ( (item_number > 15) || (item_number < 1) )
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
													
													printf("\nEnter size (Enter 'L' for Large and 'X' for Extra-Large): ");
													scanf(" %c", &size);
													if ( size == 'l' )
														size = 'L';
													else if ( size == 'x' )
														size = 'X';
													if ( (size == 'L') || (size == 'X') )
													{
													item_bought( &women_bottom_trousers[item_number-2][100], &women_bottom_trousers_price[item_number-1] , &women_bottom_trousers_code[item_number-1], &size);
													printf("\nEnter 'Y' to add another item from this menu to your cart, Enter any other key to continue: ");
													scanf(" %c", &item_choice);
													if ( item_choice == 'y' )
														item_choice = 'Y';
													}
													else
													{
														printf("\nINVALID INPUT!\n");
														continue;
													}
												}
												break;
										}
									
						break; //CASE 'F' FOR FEMALE'S CLOTHING ENDS HERE.
									
									break;
									
						default:	printf("\nInavlid input!");
									break;
					}
					
					printf("\nEnter 'Y' to continue in Adults section, Enter any other key to continue: ");
					scanf(" %c", &sub_category_choice);
					if ( sub_category_choice == 'y' )
						sub_category_choice = 'Y';
					}
					break;
					
			default:	printf("\nInavlid input!");
						break;
		}
		
		
		printf("\n\nEnter Y to go back to the category menu, Enter any other key to proceed to checkout: ");
		scanf(" %c",&category_continue);
		if ( category_continue == 'y' )
			category_continue = 'Y';
		if ( category_continue == 'Y' )
		{
			main_call++;
			main();
		}
		else
		{	

		printf("\n\n'CUSTOMER INFORMATION'\n\nEnter your full name: ");
		fflush(stdin);
		fgets(info.customer_name, 40, stdin);
		printf("\nEnter phone: +92");
		fflush(stdin);
		fgets(info.customer_phone, 15, stdin);
		do
		{
		printf("\nEnter Email: ");
		fflush(stdin);
		fgets(info.customer_email, 40, stdin);
		if ( !strstr(info.customer_email, "@gmail.com") )
			printf("\nINVALID EMAIL ID!\n");
		}
		while ( !strstr(info.customer_email, "@gmail.com") );
		
		printf("\n'SHIPPING ADDRESS'\n\nEnter province: ");
		fflush(stdin);
		fgets(info.shipping_province, 15, stdin);
		printf("\nEnter City: ");
		fflush(stdin);
		fgets(info.shipping_city, 15, stdin);
		printf("\nEnter Address: ");
		fflush(stdin);
		fgets(info.shipping_address, 100, stdin);
		printf("\nEnter Postal Code: ");
		scanf(" %d", &info.shipping_postal_code);
		
		char address_choice;
		do
		{
		printf("\nIs your billing address the same as your shipping address? Enter 'Y' or 'N' ");
		scanf(" %c", &address_choice);
		if ( address_choice == 'y' )
			address_choice = 'Y';
		if ( address_choice == 'n' )
			address_choice = 'N';
		
		if ( (address_choice == 'Y') || (address_choice == 'N') )
			break;
		}
		while ( 1 );
		
		switch( address_choice )
		{
			case 'Y':	strcpy( info.billing_province, info.shipping_province );
						strcpy( info.billing_city, info.shipping_city );
						strcpy( info.billing_address, info.shipping_address );
						info.billing_postal_code = info.shipping_postal_code;
						break;
			
			case 'N':	printf("\n'BILLING ADDRESS'\n\nEnter province: ");
						fflush(stdin);
						fgets(info.billing_province, 15, stdin);
						printf("\nEnter City: ");
						fflush(stdin);
						fgets(info.billing_city, 15, stdin);
						printf("\nEnter Address: ");
						fflush(stdin);
						fgets(info.billing_address, 100, stdin);
						printf("\nEnter postal code: ");
						scanf(" %d", &info.billing_postal_code);
						break;
			
			default:	printf("\nINVALID INPUT!\n");
						break;
		}
		
		char shipping_postal_code[10], billing_postal_code[10], price_code_size[40];
		
		sprintf(shipping_postal_code, "%d", info.shipping_postal_code);
		sprintf(billing_postal_code, "%d", info.billing_postal_code);
		
		
		save_info( info.customer_name, info.customer_email,info.customer_phone, info.shipping_province, info.shipping_city, info.shipping_address, shipping_postal_code, info.billing_province, info.billing_city, info.billing_address, billing_postal_code );
		
		for (i=0; i<counter; i++)
		{
			sprintf(price_code_size, "%d \t%d\t%c", prices[i], codes[i], size_global[i]);
			save_order( description[i], price_code_size);
		}
		
		printf("\n\n\t  CHECKOUT\n\t  --------\n\nYOUR CART CONTAINS FOLLOWING ITEMS:\n\nno.\t\tITEM NAME \t\t\t\t\t\t  PRICE \tCODE \tSIZE\n---\t\t---- ---- \t\t\t\t\t\t  ----- \t---- \t----");
		for (i=0; i<counter; i++)
		{
			printf("\n%d.\t %s \t Rs.%d \t%d \t%c", i+1, description[i], prices[i], codes[i], size_global[i] );
		}
		
		printf("\n\nCUSTOMER INFORMATION\n-------- -----------\n\nName: %s \nEMAIL: %s \nPhone: +92%s \n\nSHIPPING ADDRESS\n-------- -------\n\nProvince: %s \nCity: %s \nAdress: %s \nPostal Code: %d \n\nBILLING ADDRESS\n------- -------\n\nProvince: %s \nCity: %s \nAdress: %s \nPostal Code: %d", info.customer_name, info.customer_email, info.customer_phone, info.shipping_province, info.shipping_city, info.shipping_address, info.shipping_postal_code, info.billing_province, info.billing_city, info.billing_address, info.billing_postal_code);
		
		printf("\n\nTOTAL AMOUNT BEFORE DESCOUNT: Rs.%d", total_amount);
		
	FILE *fileptr;
	fileptr = fopen( "Information.txt", "a" );
	if ( fileptr == NULL )
		printf("\nFile could not be opened\n");
	else
	{
		fprintf(fileptr,"\n\nTOTAL AMOUNT BEFORE DESCOUNT: Rs.%d", total_amount );
		fclose(fileptr);
	}
		
		if ( total_amount >= 30000 )
			total_amount = total_amount - ((total_amount / 100) * 40 );
		else if ( total_amount >= 20000 )
			total_amount = total_amount - ((total_amount / 100) * 20 );
		else if ( total_amount >= 10000 )
			total_amount = total_amount - ((total_amount / 100) * 10 );
			
	fileptr = fopen( "Information.txt", "a" );
	if ( fileptr == NULL )
		printf("\nFile could not be opened\n");
	else
	{
		fprintf(fileptr,"\n\nTOTAL AMOUNT AFTER DISCOUNT: Rs.%d", total_amount );
		fclose(fileptr);
	}
		
	printf("\n\nTOTAL AMOUNT AFTER DISCOUNT: Rs.%d", total_amount);
		
	printf("\n\n\t\t  * * * * * * *\n\t\t  *   *  *    *\n"             "\t\t  *  ******   *   - - - - - - - - - - - - - -\n\t\t  * * * * * * *                             |\n\t\t      ****                                  |\n\t      * * * * * * * * * * *  \t                    |\n\t* * * *                   * * * *          * * * * * * * * * * *\n\t* * * *  * * * * * * * *  * * * *          * IT WAS A PLEASURE *\n\t* *   *  *SHOP-IN STORE*  *   * *          *   TO SERVE YOU    *\n\t* *   *  *   CHATBOT   *  *   * *          * * * * * * * * * * *\n\t* *   *  * * * * * * * *  *   * *\n\t***   *                   *   ***\n\t      * * * * * * * * * * *                           You will recieve a confirmation email shortly\n\t        *  *        *  *                                            Have a Good Day!\n\t        *  *        *  *         \n\t        *  *        *  *         \n\t        *  *        *  *         \n\t        ****        ****         \n" );
	//outro
	}
	
	return 0;
}
