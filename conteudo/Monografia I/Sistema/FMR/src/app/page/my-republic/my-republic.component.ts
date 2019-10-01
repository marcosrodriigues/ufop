import { Component, OnInit } from '@angular/core';
import * as CanvasJS from '../../../assets/js/canvasjs.min';
import { UserService } from 'src/app/service/user.service';

@Component({
  selector: 'app-my-republic',
  templateUrl: './my-republic.component.html',
  styleUrls: ['./my-republic.component.css']
})
export class MyRepublicComponent implements OnInit {

  profile : any = { }

  constructor(private _user : UserService) { 
  }

  ngOnInit() {
    this._user.checkCredentials();
    this._user.me().subscribe( (data: any) => {
      this.profile = data.moradorRepublica.republica;
    })
  }

}
