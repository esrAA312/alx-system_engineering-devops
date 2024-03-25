package { 'nginx':
	  ensure => installed,
}

file_line { 'redirect':
	  ensure => present,
		   path   => '/etc/nginx/sites-enabled/default',
		     line   => 'rewrite ^/redirect_me https://www.github.com/besthor permanent;',
		       after  => 'listen 80 default_server;',
}

file { '/var/www/html/index.html':
	  ensure  => file,
		    content => 'Hello World!',
}

service { 'nginx':
	  ensure  => running,
		    enable  => true,
		      require => Package['nginx'],
}
