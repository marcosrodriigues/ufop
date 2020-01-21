import { Component, OnInit } from '@angular/core';
import { UserService } from 'src/app/service/user.service';


@Component({
  selector: 'app-profile',
  templateUrl: './profile.component.html',
  styleUrls: ['./profile.component.css']
})
export class ProfileComponent implements OnInit {
    
  constructor(private _userService : UserService) { }

  profile : any = { }

  ngOnInit() {
    this._userService.checkCredentials();
    this.initMe();
  }

  initMe() {
    this._userService.me().subscribe(data => {
      this.profile = data;
    }, err => {
    });
  }
  
}
