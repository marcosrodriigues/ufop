import { Component, OnInit, Input, OnChanges } from '@angular/core';

@Component({
  selector: 'app-profile-republica',
  templateUrl: './profile-republica.component.html',
  styleUrls: ['./profile-republica.component.css']
})
export class ProfileRepublicaComponent implements OnInit, OnChanges {

  @Input("profile") profile : any = { }

  constructor() { }

  ngOnChanges() {
    
  }

  ngOnInit() {
  }

}
