/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   define.h										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/23 18:44:10 by gkoller		   #+#	#+#			 */
/*   Updated: 2024/12/23 18:44:10 by gkoller		  ###   ########.ch	   */
/*																			*/
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# ifdef __APPLE__
#  include <TargetConditionals.h>
# endif
# include "include.h"

//jeu
# define FOV			    60
# define PLAYERHEIGHT 	  	32
# define WALLHEIGHT 	    64
# define SIZESQUARE		    64
# define SPEED			    5
# define ROT_SPEED		    2

//collision
# define DST_COL			10

//minimap
# define MINISIZE 			100
# define POS      			50
# define COLOR_FLOOR  		0x808080
# define COLOR_WALL   		0x151B54
# define COLOR_PLAYER 		0xFF0000
# define COLOR_TRANS 		-1

//fenetre
# define WIDTH		        1200
# define HEIGHT		        960

//utils
# define PI			        3.14159265358

//touches
# ifdef __APPLE__
// macOS keycodes
#  define ESC             	53
#  define UP              	13   // w
#  define DOWN            	1    // s
#  define LEFT            	0    // a
#  define RIGHT           	2    // d
#  define F_LEFT          	123  // ←
#  define F_RIGHT         	124  // →
# else
// Linux (X11) keycodes
#  define ESC             	65307
#  define UP              	119
#  define DOWN            	115
#  define LEFT            	97
#  define RIGHT           	100
#  define F_LEFT          	65361
#  define F_RIGHT         	65363
# endif

#endif