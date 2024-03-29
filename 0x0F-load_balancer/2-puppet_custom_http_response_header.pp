#pp
exec { 'update':
	command  => 'apt-get update',
		 user     => 'root',
		 path     => '/usr/bin:/usr/sbin:/bin',
}

package { 'nginx':
	ensure  => 'installed',
		require => Exec['update'],
}

file { '/etc/nginx/sites-available/default':
	ensure  => 'file',
		content => "\
			 location / {
				 add_header X-Served-By ${hostname};
				 ",
					 require => Package['nginx'],
			 }

	service { 'nginx':
		ensure    => 'running',
		enable    => true,
		subscribe => File['/etc/nginx/sites-available/default'],
	}
