#!/usr/bin/pup
#install
package { 'Flask':
    ensure   => '2.1.0',
    provider => 'pip3'
}
