import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { MyRepublicComponent } from './my-republic.component';

describe('MyRepublicComponent', () => {
  let component: MyRepublicComponent;
  let fixture: ComponentFixture<MyRepublicComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ MyRepublicComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(MyRepublicComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
