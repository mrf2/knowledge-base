/*
 * filename: echo_server.c
 */

int main(int argc, char **argv)
{
	int listenfd;
	int connectfd;
	int port;
	int clientlen;

	/*	
	struct sockaddr_in {
	  __kernel_sa_family_t	sin_family;	// Address family		
	  __be16		sin_port;	// Port number			
	  struct in_addr	sin_addr;	// Internet address		

	  // Pad to size of `struct sockaddr'. 
	  unsigned char		__pad[__SOCK_SIZE__ - sizeof(short int) -
				sizeof(unsigned short int) - sizeof(struct in_addr)];
	}; */
	struct sockaddr_in clientaddr;
struct hostent
{
  char *h_name;			/* Official name of host.  */
  char **h_aliases;		/* Alias list.	*/
  int h_addrtype;		/* Host address type.  */
  int h_length;			/* Length of address.  */
  char **h_addr_list;		/* List of addresses from name server.	*/
#ifdef __USE_MISC
# define	h_addr	h_addr_list[0] /* Address, for backward compatibility.*/
#endif
};
extern struct hostent *gethostent (void);

/* Return entry from host data base which address match ADDR with
   length LEN and type TYPE.

   This function is a possible cancellation point and therefore not
   marked with __THROW.	 */
extern struct hostent *gethostbyaddr (const void *__addr, __socklen_t __len,
				      int __type);

/* Return entry from host data base for host with NAME.

   This function is a possible cancellation point and therefore not
   marked with __THROW.	 */
extern struct hostent *gethostbyname (const char *__name);

#ifdef __USE_MISC
/* Return entry from host data base for host with NAME.	 AF must be
   set to the address type which is `AF_INET' for IPv4 or `AF_INET6'
   for IPv6.

   This function is not part of POSIX and therefore no official
   cancellation point.	But due to similarity with an POSIX interface
   or due to the implementation it is a cancellation point and
   therefore not marked with __THROW.  */
extern struct hostent *gethostbyname2 (const char *__name, int __af);

/* Reentrant versions of the functions above.  The additional
   arguments specify a buffer of BUFLEN starting at BUF.  The last
   argument is a pointer to a variable which gets the value which
   would be stored in the global variable `herrno' by the
   non-reentrant functions.

   These functions are not part of POSIX and therefore no official
   cancellation point.	But due to similarity with an POSIX interface
   or due to the implementation they are cancellation points and
   therefore not marked with __THROW.  */
extern int gethostent_r (struct hostent *__restrict __result_buf,
			 char *__restrict __buf, size_t __buflen,
			 struct hostent **__restrict __result,
			 int *__restrict __h_errnop);

extern int gethostbyaddr_r (const void *__restrict __addr, __socklen_t __len,
			    int __type,
			    struct hostent *__restrict __result_buf,
			    char *__restrict __buf, size_t __buflen,
			    struct hostent **__restrict __result,
			    int *__restrict __h_errnop);

extern int gethostbyname_r (const char *__restrict __name,
			    struct hostent *__restrict __result_buf,
			    char *__restrict __buf, size_t __buflen,
			    struct hostent **__restrict __result,
			    int *__restrict __h_errnop);

extern int gethostbyname2_r (const char *__restrict __name, int __af,
			     struct hostent *__restrict __result_buf,
			     char *__restrict __buf, size_t __buflen,
			     struct hostent **__restrict __result,
			     int *__restrict __h_errnop);
#endif	/* misc */


/* Open network data base files and mark them as staying open even
   after a later search if STAY_OPEN is non-zero.

   This function is a possible cancellation point and therefore not
   marked with __THROW.	 */
extern void setnetent (int __stay_open);

/* Close network data base files and clear `stay open' flag.

   This function is a possible cancellation point and therefore not
   marked with __THROW.	 */
extern void endnetent (void);

/* Get next entry from network data base file.	Open data base if
   necessary.

   This function is a possible cancellation point and therefore not
   marked with __THROW.	 */
extern struct netent *getnetent (void);

/* Return entry from network data base which address match NET and
   type TYPE.

   This function is a possible cancellation point and therefore not
   marked with __THROW.	 */
extern struct netent *getnetbyaddr (uint32_t __net, int __type);

/* Return entry from network data base for network with NAME.

   This function is a possible cancellation point and therefore not
   marked with __THROW.	 */
extern struct netent *getnetbyname (const char *__name);

#ifdef	__USE_MISC
/* Reentrant versions of the functions above.  The additional
   arguments specify a buffer of BUFLEN starting at BUF.  The last
   argument is a pointer to a variable which gets the value which
   would be stored in the global variable `herrno' by the
   non-reentrant functions.

   These functions are not part of POSIX and therefore no official
   cancellation point.	But due to similarity with an POSIX interface
   or due to the implementation they are cancellation points and
   therefore not marked with __THROW.  */
extern int getnetent_r (struct netent *__restrict __result_buf,
			char *__restrict __buf, size_t __buflen,
			struct netent **__restrict __result,
			int *__restrict __h_errnop);

extern int getnetbyaddr_r (uint32_t __net, int __type,
			   struct netent *__restrict __result_buf,
			   char *__restrict __buf, size_t __buflen,
			   struct netent **__restrict __result,
			   int *__restrict __h_errnop);

extern int getnetbyname_r (const char *__restrict __name,
			   struct netent *__restrict __result_buf,
			   char *__restrict __buf, size_t __buflen,
			   struct netent **__restrict __result,
			   int *__restrict __h_errnop);
#endif	/* misc */


/* Description of data base entry for a single service.	 */
struct servent
{
  char *s_name;			/* Official service name.  */
  char **s_aliases;		/* Alias list.	*/
  int s_port;			/* Port number.	 */
  char *s_proto;		/* Protocol to use.  */
};

	
