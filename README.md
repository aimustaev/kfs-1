# KFS-1

## Создание img
- `qemu-img create -f raw hard_disk.img 1G`
- `modprobe loop max_part=15`
- `losetup -f hard_disk.img`
- `losetup`
- `gparted /dev/loopXXX`
- `mount /dev/loopXXXp1 /mnt/os`
- `mkdir /mnt/os/boot`
- `grub-install --root-directory=/mnt/os /dev/loopXXX`
- `cp ./kernel /mnt/os/boot/`
- `cp ./kernel /mnt/os/boot/`
- `make start_disk`

check_sum hard_disk.img

```
MD5(hard_disk.img)= 99f2e825e787adc8f60eb57a5b7af340
```