#stup New Ubuntu server with nginx
# and add a custom HTTP header

exec { 'update system':
	command => '/usr/bin/apt-get update',
}

package { 'nginx':
	ensure  => 'installed',
		require => Exec['update system'],
}

file { '/var/www/html/index.html':
	content => 'Hello World!',
}

exec { 'configure nginx':
	command  => 'sed -i "24i\        rewrite ^/redirect_me https://th3-gr00t.tk/ permanent;" /etc/nginx/sites-available/default && \
		  sed -i "25i\        add_header X-Served-By \$hostname;" /etc/nginx/sites-available/default',
		 provider => 'shell',
		 require  => Package['nginx'],
		 notify   => Service['nginx'],
}

service { 'nginx':
	ensure    => 'running',
		  enable    => true,
		  require   => Package['nginx'],
}

# Alternative approach using Puppet's built-in resources
exec { 'update':
	command  => 'apt-get update',
		 path     => '/usr/bin:/usr/sbin:/bin',
}

package { 'nginx':
	ensure   => 'present',
		 require  => Exec['update'],
}

file_line { 'header line':
	ensure => present,
	       path   => '/etc/nginx/sites-available/default',
	       line   => "        location / {\n  add_header X-Served-By ${hostname};",
	       match  => '^\s*location / {',
		       require => Package['nginx'],
	       }

	exec { 'restart service':
		command  => 'service nginx restart',
		path     => '/usr/bin:/usr/sbin:/bin',
		provider => shell,
		require  => Package['nginx'],
	}
