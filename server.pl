#!/usr/bin/perl -w
# udpqotd - UDP message server

	use strict;
	use IO::Socket;

	my $sock;
	my $data;
	my $client_addr; 
	my $buffer;
	my $server_port;
	my $i;
	my $numb;
	my $clients;
	my $clients_active;
	my @client_data;
	my @temp;
	
	my $id;
	my $busena;
	my $tanko_x;
	my $tanko_y;
	my $tanko_angle;
	my $patranka_angle;
	my @sovinys_x;
	my @sovinys_y;
	
	my $pack;
	
	$buffer = 512;
	$server_port = 5151;
	$numb = $clients = 0;
	$clients_active=0;
	
	$i = 0;
	$pack = "";
	
	$sock = IO::Socket::INET->new(
		LocalPort => $server_port,
		Proto => 'udp')
	or die "socket: $@";
	
	print "Laukiam prisijungimu per porta: $server_port\n";

	while ( $sock->recv($data, $buffer) ) {
		
		my( $port, $ipaddr ) = sockaddr_in( $sock->peername );
		$client_addr = gethostbyaddr( $ipaddr, AF_INET );
		if ($i >= 10000) {$i = 0; }
		$i++;
		
		if ($data =~m/hello/) {		
			$sock->send($numb."\0");
			print "$i Gautas pasisveikinimas, suteikiamas $numb id !\n";
			$numb++;
			$clients++;
			$client_data[$numb][0] = "-1";
		}	
		elsif ($data =~ m/get/) {
			print "$i Siunciamos wisos koordinates - Atsakom i $data\n";
		}
		elsif ($data =~ m/bye/) {
			@temp = split(/ +/, $data);			
			$id = $temp[0];
			$client_data[$id][0] = "-1";
			$clients--;
			print "$i Klientas $id atsijunge\n";		
		} else {		
			@temp = split(/ +/, $data);			
			$id = $temp[0];
			
			$client_data[$id][0] = $busena = $temp[1] ;  #busena
			$client_data[$id][1] = $tanko_x = $temp[2] ;  #tanko x
			$client_data[$id][2] = $tanko_y = $temp[3] ;  #tanko y
			$client_data[$id][3] = $tanko_angle = $temp[4];  #tanko angle
			$client_data[$id][4] = $patranka_angle = $temp[5];  #puskos angle
			$client_data[$id][5] = $sovinys_x[0] = $temp[6];  #sovinio1 x
			$client_data[$id][6] = $sovinys_y[0] = $temp[7];  #sovinio1 y
			
			print "$i Server <- ID:$id bus:$busena $tanko_x:$tanko_y $tanko_angle $patranka_angle sov: [$sovinys_x[0]:$sovinys_y[0]]\n";
			
			$clients_active = 0;
			for ($a=0; $a <= $clients; $a++) {
				if (($client_data[$a][0] ne "-1") && ($a != $id)) {
					$clients_active++;
				}
			}
			
			$pack .= $clients_active;
			$pack .= " ";
			
			for( $a = 0; $a < $clients; $a++ ) 
			{
				if ( ($a != $id)  && ($client_data[$a][0] ne "-1") ) {
					$pack .= $a." "; #id
					$pack .= $client_data[$a][0]." "; #busena
					$pack .= $client_data[$a][1]." "; #tanko x
					$pack .= $client_data[$a][2]." "; #tanko y
					$pack .= $client_data[$a][3]." ";
					$pack .= $client_data[$a][4]." ";
					$pack .= $client_data[$a][5]." ";
					$pack .= $client_data[$a][6]." ";
				}
			}
			print "$i Server -> ID:$id \"$pack\"\n";
			$sock->send($pack."\0");
			$pack = "";
		}
		
	} 
	die "recv: $!";
